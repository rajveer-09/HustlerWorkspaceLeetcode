#include <optional>
#include <memory>
#include <cstring>

struct DefaultHash {
  template<class T>
  uint64_t operator()(T x) const {
    if constexpr (std::is_integral_v<T>) {
      return x * 0xaef17502108ef2d9;
    }

    constexpr std::hash<T> hasher;
    return hasher(x);
  }
};


template<class KeyType, class ValType, class Hash = DefaultHash>
class ArrayHashTrie {
private:
  static constexpr size_t BITS = 3;
  static constexpr Hash hasher = {};

  struct Node {
    uint32_t children[1 << BITS];
    KeyType key;
    ValType value;
  };

  uint32_t nodes_cap = 1;
  uint32_t nodes_len = 1;
  std::unique_ptr<Node[]> nodes = std::make_unique<Node[]>(nodes_cap);

public:
  ValType *upsert(KeyType key, std::optional<ValType> default_value = std::nullopt) {
    uint32_t ptr = 0;
    uint32_t child = 0;
    uint32_t node_idx = nodes[0].children[0];

    uint64_t hash = hasher(key);

    while (node_idx && nodes[node_idx].key != key) {
      ptr = node_idx;
      child = hash >> (64 - BITS);
      node_idx = nodes[ptr].children[child];

      hash <<= BITS;
    }

    if (node_idx == 0) {
      if (default_value.has_value()) {
        if (nodes_len == nodes_cap) {
          nodes_cap <<= 1;

          std::unique_ptr<Node[]> new_nodes = std::make_unique<Node[]>(nodes_cap);
          memcpy(new_nodes.get(), nodes.get(), sizeof(Node) * nodes_len);

          nodes.swap(new_nodes);
        }

        Node *new_node = &nodes[nodes_len];
        new_node->key = key;
        new_node->value = default_value.value();

        nodes[ptr].children[child] = nodes_len++;
        return &new_node->value;
      }

      return nullptr;
    }

    return &nodes[node_idx].value;
  }

  ArrayHashTrie clone() {
    ArrayHashTrie other;

    other.nodes_cap = nodes_cap;
    other.nodes_len = nodes_len;
    other.nodes = std::make_unique<Node[]>(sizeof(Node) * nodes_cap);

    memcpy(other.nodes.get(), nodes.get(), sizeof(Node) * nodes_len);

    return other;
  }

  Node *begin() {
    return nodes.get() + 1;
  }

  Node *end() {
    return nodes.get() + nodes_len;
  }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;

        ArrayHashTrie<int64_t, int> map;

        int64_t sum = 0;
        *map.upsert(k, 0) = 1;

        for (int num : nums) {
            sum += num;

            int *node = map.upsert(sum);
            if (node) result += *node;

            ++*map.upsert(k + sum, 0);
        }

        return result;
    }
};
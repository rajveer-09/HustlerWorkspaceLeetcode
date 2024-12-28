class Solution {
    public int calPoints(String[] operations) {
        int output = 0;
        ArrayList<Integer> list = new ArrayList<>();

        for (String operation : operations) {
            if (operation.equals("C")) {
                // Remove the previous score
                list.remove(list.size() - 1);
            } else if (operation.equals("D")) {
                // Add the double of the previous score
                list.add(list.get(list.size() - 1) * 2);
            } else if (operation.equals("+")) {
                // Add the sum of the previous two scores
                int size = list.size();
                list.add(list.get(size - 1) + list.get(size - 2));
            } else {
                // Add the integer value
                list.add(Integer.parseInt(operation));
            }
        }

        for (int score : list) {
            output += score;
        }

        return output;
    }
}
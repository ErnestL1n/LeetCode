    public String modifyString(String s) {
        char[] arr = s.toCharArray();
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == '?') {
                for (int j = 0; j < 3; j++) {
                    if (i > 0 && arr[i - 1] - 'a' == j) continue;
                    if (i + 1 < arr.length && arr[i + 1] - 'a' == j) continue;
                    arr[i] = (char) ('a' + j);
                    break;
                }
            }
        }
        return String.valueOf(arr);
    }
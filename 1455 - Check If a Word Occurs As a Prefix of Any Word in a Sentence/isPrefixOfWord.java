// Java Solution
class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {
        // Split sentence into a array of strings
        String[] words = sentence.split("\\s+");
        for (int i = 0; i < words.length; i++) {
            words[i] = words[i].replaceAll("[^\\w]", "");
        }

        // compare
        for ( int i = 0; i < words.length; i++ ){
            if ( words[i].length() < searchWord.length() ) continue;
            if ( words[i].substring(0,searchWord.length()).equals(searchWord) == true )
                return i+1;
        }
        return -1;
    }
}


import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class sovle {
    public static void main(String[] args) {
        int result;
        Scanner scanner = new Scanner(System.in);
        int length1 = 0;
        int length2 = 0;
        while(scanner.hasNext()){
            length1 = scanner.nextInt();
            length2 = scanner.nextInt();
        }

        ArrayList<Integer> list1 = new ArrayList<Integer>();
        ArrayList<Integer> list2 = new ArrayList<Integer>();

        for (int i = 0; i < length1; i++) {
            list1.add(scanner.nextInt());
        }

        for (int i = 0; i < length2; i++) {
            list2.add(scanner.nextInt());
        }

        int min = findmin(list2);
        list1.sort(comparator);

        int index = -1;
        for (int i = 0; i < length1; i++) {
            if(min > list1.get(i)){
                index = i;
            }
        }
        if(index == -1){
            result = list1.get(0) - min;
        }else{
            int a = min - list1.get(index);
            int b = list1.get(index-1) - min;
            if(a <= b){
                result = a;
            }else {
                result = b;
            }
        }
    }

    public static int findmin(ArrayList<Integer> list){
        int i = 0;
        int min = 999999;
        while(i<list.size()){
            if(list.get(i)<min){
                min = list.get(i);
            }
        }
        return min;
    }

    public void al() {
        String[] strs = {"abcd", "kbcd", "cbcd"};
        String tem = "";
        if (strs == null || strs.length == 0) tem = "";
        for (int i = 0; i < strs[0].length() ; i++){
            char c = strs[0].charAt(i);
            for (int j = 1; j < strs.length; j ++) {
                if (i == strs[j].length() || strs[j].charAt(i) != c)
                    tem = strs[0].substring(0, i);
            }
        }
        System.out.println(tem);
    }


    static Comparator<Integer> comparator = new Comparator<Integer>() {
        @Override
        public int compare(Integer p1 , Integer p2 ) {
            return p1>p2?p1:p2;
        }
    };

}

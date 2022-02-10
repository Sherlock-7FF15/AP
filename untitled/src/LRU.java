import java.util.LinkedList;

public class LRU {

    private LinkedList<Integer> stack;//模拟页面'寄存器'
    private int size;//寄存器大小,表示一共可装入多少页面

    public LRU(int size) {
        stack = new LinkedList<>();
        this.size = size;
    }

    //LRU算法简单实现,返回一共未命中的次数
    public int lru(int[] pageNumbers)
    {
        if(size <= 0 || pageNumbers == null)
            throw new IllegalArgumentException("illegal arugments");

        if(pageNumbers.length <= size)
            return pageNumbers.length;

        int unhit = 0;

        for(int i = 0; i < pageNumbers.length; i++)
        {
            int index = isHit(pageNumbers[i]);
            if(index == -1)
                unhit = processUnHit(pageNumbers[i], unhit);
            else
            {
                processHit(pageNumbers[i], index);
            }
        }
        return unhit;
    }

    /**
     *
     * @param pageNumber 判断 pageNumber是否hit
     * @return -1 表示 unhit, 其他表示hit
     */
    private int isHit(int pageNumber){
        return stack.indexOf(pageNumber);
    }

    /**
     * 当栈未满时,未命中的页面号直接入栈;栈满时,需要替换页面,先选中一个页面(栈底)删除,然后Push新页面
     * @param pageNumber 未命中的页面号
     * @param count 当前未命中次数
     * @return 更新后的未命中的次数
     */
    private int processUnHit(int pageNumber, int count){
        if(isFull())
            stack.removeLast();//删除最久未访问的页面
        stack.push(pageNumber);//放入最近访问的页面
        count++;//未命中的次数加1
        return count;
    }

    //处理命中的情况
    private void processHit(int pageNumber, int index){
        stack.push(stack.remove(index));
    }

    //判断'寄存器'栈是否已经满了
    private boolean isFull()
    {
        if(stack.size() < size)
            return false;
        else
            return true;
    }
//
//    //test
//    public static void main(String[] args) {
//        int[] pageNumbers = {4,7,1,1,7,2,1};
//        int size = 2;
//        LRU lru = new LRU(size);
//        System.out.println(lru.lru(pageNumbers));
//    }
}
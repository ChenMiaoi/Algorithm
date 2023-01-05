#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
 * 整个程序的整体设计是：
 *      首先，我们需要处理六个数据集对应的数据，因此我们写了六个相似的函数分别处理对应的数据集
 *      然后，我们写出对应的六个排序函数，设置好定时器
 *      再者，我们再写出一个读取数据，和将数据存在进文件的函数
 *      最后，将各部分功能整合即可
 * */

// 对应data数据集的数据个数
#define DATA1_NUM 11
#define DATA2_NUM 1000
#define DATA3_NUM 10000
#define DATA4_NUM 100000
#define DATA5_NUM 100000
#define DATA6_NUM 100000

// 对应data数据集的绝对位置，需要自行更改正确的路径
#define PATH_DATA1 "./data1.txt"
#define PATH_DATA2 "./data2.txt"
#define PATH_DATA3 "./data3.txt"
#define PATH_DATA4 "./data4.txt"
#define PATH_DATA5 "./data5.txt"
#define PATH_DATA6 "./data6.txt"

// 对应result输出的绝对位置，需要自行更改正确的路径
#define PATH_RESULT1 "./result1.txt"
#define PATH_RESULT2 "./result2.txt"
#define PATH_RESULT3 "./result3.txt"
#define PATH_RESULT4 "./result4.txt"
#define PATH_RESULT5 "./result5.txt"
#define PATH_RESULT6 "./result6.txt"

clock_t start, end; // 用于计时，计时结果为end - start
long int num[1000000]; // 存储数据的数组
FILE* fp; // 文件指针

void deal_data1() { // 处理data1数据集的函数，将数据存放到data1.txt中
    fp = fopen(PATH_DATA1, "w+"); // 如果没有该文件，就创建，如果有，则清空文件中的内容方式打开
    int n = 0, temp = 0;
    if (fp != NULL) { // 如果文件打开成功
        printf("请输入你想要测试的数据(只能是11)：");
        setbuf(stdout, NULL); // 防止缓冲区无法显示信息的bug，将缓冲区设置为无缓冲
        scanf("%d", &n);
        printf("请输入11位数据进行排序：\n");
        setbuf(stdout, NULL);
        for (int i = 0; i < n; i++) {
            scanf("%d", &temp);
            fprintf(fp, "%d ", temp); // 将数据输入进data1文件中
        }
    }else {
        perror("deal_data1 open error!"); // 错误输出函数，传入信息然后输出对应的信息
    }
    fclose(fp); // 关闭文件
}

void deal_data2() { // 处理data2数据集的函数，将数据存放到data2.txt中
    fp = fopen(PATH_DATA2, "w+");
    if (fp != NULL) {
        for (int i = 0; i <= (int)pow(10, 3); i++) { // pow(10, 3)表示10的三次方，强转为int是因为pow返回的类型是double
            fprintf(fp, "%d ", rand() % 1000 + 1);
            // rand()函数返回一个随机数，而 %1000 + 1就是让其控制在0~1000中随机
        }
    }else {
        perror("deal_data2 open error!");
    }
    fclose(fp);
}

void deal_data3() { // 处理data3数据集的函数，将数据存放到data3.txt中，原理和data2一致
    fp = fopen(PATH_DATA3, "w+");
    int n = 0, temp = 0;
    if (fp != NULL) {
        for (int i = 0; i <= (int) pow(10, 4); i++) {
            fprintf(fp, "%d ", rand() % 10000);
            // rand()函数返回一个随机数，而 %10000 + 1就是让其控制在0~10000中随机
        }
    }else {
        perror("deal_data3 open error!");
    }
    fclose(fp);
}

void deal_data4() { // 处理data4数据集的函数，将数据存放到data4.txt中，原理和data2一致
    fp = fopen(PATH_DATA4, "w+");
    int n = 0, temp = 0;
    if (fp != NULL) {
        for (int i = 0; i <= (int) pow(10, 5); i++) {
            fprintf(fp, "%d ", rand() % 100000);
        }
    }else {
        perror("deal_data4 open error!");
    }
    fclose(fp);
}

void deal_data5() { // 处理data5数据集的函数，将数据存放到data5.txt中，原理和data2一致
    fp = fopen(PATH_DATA5, "w+");
    int n = 0, temp = 0;
    if (fp != NULL) {
        for (int i = 0; i <= (int) pow(10, 5); i++) { // 此处是进行顺序输出到10的5次方
            fprintf(fp, "%d ", i);
        }
    }else {
        perror("deal_data5 open error!");
    }
    fclose(fp);
}

void deal_data6() { // 处理data6数据集的函数，将数据存放到data6.txt中，原理和data2一致
    fp = fopen(PATH_DATA6, "w+");
    int n = 0, temp = 0;
    if (fp != NULL) {
        for (int i = (int) pow(10, 5); i >=0 ; i--) { // 此处是进行逆序输出到10的5次方
            fprintf(fp, "%d ", i);
        }
    }else {
        perror("deal_data6 open error!");
    }
    fclose(fp);
}

void deal_data() { // 为了不让代码太过于臃肿，统一封装一下函数调用
    deal_data1();
    deal_data2();
    deal_data3();
    deal_data4();
    deal_data5();
    deal_data6();
}

void read_file(char* file_name) { // 读取data数据集函数操作
    memset(num, 0, 1000000); // 初始化一下数组，为了防止之前的数据干扰到我们读取文件数据
    fp = fopen(file_name, "r"); // 以只读的形式读取文件
    if (fp != NULL) {
        int i = 0;
        while (!feof(fp)) { // 如果没有到达文件末尾，就进入循环，feof判断是否到达文件末尾
            fscanf(fp, "%ld ", &num[i++]); // 读取文件中的数据
        }
    }else {
        perror("read_file(char* file_name) error!");
    }
    fclose(fp);
}

void out_put(char* msg, char* file_name, int n) { // 输出排序好的数据进对应的result文件
    fp = fopen(file_name, "a+");
    if (fp != NULL) {
        int i = 0;
        fprintf(fp, "%s:\n\t", msg); // 做一个美观处理，在文件中输出一下是哪一个排序的数据
        while (num[i] != '\0' || i <= n) { // 当数据到末尾，或者遍历完时才会终止
            fprintf(fp, "%ld ", num[i++]); // 向文件中输入数据
        }
        fprintf(fp, "\n"); // 在文件中换行，也是美观处理
    }else {
        perror("out_put(char* file_name, int n) error!");
    }
    fclose(fp);
}

void clean_file() { // 清空文件内容，避免了每次都要手动删除数据
    fp = fopen(PATH_RESULT1, "w+");
    fclose(fp);
    fp = fopen(PATH_RESULT2, "w+");
    fclose(fp);
    fp = fopen(PATH_RESULT3, "w+");
    fclose(fp);
    fp = fopen(PATH_RESULT4, "w+");
    fclose(fp);
    fp = fopen(PATH_RESULT5, "w+");
    fclose(fp);
    fp = fopen(PATH_RESULT6, "w+");
    fclose(fp);
}

void InsertSort(long int a[], int n) { // 直接插入排序
    for(int i = 1; i < n; i++){
        if(a[i] < a[i-1]){ //若第 i 个元素大于 i-1 元素则直接插入；反之，需要找到适当的插入位置后在插入。
            int j = i-1;
            int x = a[i];
            while(j > -1 && x < a[j]){  //采用顺序查找方式找到插入的位置，在查找的同时，将数组中的元素进行后移操作，给插入元素腾出空间
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = x;      //插入到正确位置
        }
    }
}

void SelectSort(long int a[],int n) { //选择排序
    for(int i=0;i<n-1;i++){ //每次循环数组，找出最小的元素，放在前面，前面的即为排序好的
        int min=i; //假设最小元素的下标
        for(int j=i+1;j<n;j++) //将上面假设的最小元素与数组比较，交换出最小的元素的下标
            if(a[j]<a[min])
                min=j;
        //若数组中真的有比假设的元素还小，就交换
        if(i != min) {
            int temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
}

void ShellSort(long int a[], int n) { // 希尔排序
    int i, j, k, tmp, gap;  // gap 为步长
    for (gap = n / 2; gap > 0; gap /= 2) {  // 步长初始化为数组长度的一半，每次遍历后步长减半,
    	for (i = 0; i < gap; ++i) { // 变量 i 为每次分组的第一个元素下标
	        for (j = i + gap; j < n; j += gap) { //对步长为gap的元素进行直插排序，当gap为1时，就是直插排序
	            tmp = a[j];  // 备份a[j]的值
	            k = j - gap;  // k初始化为i的前一个元素（与i相差gap长度）
	            while (k >= 0 && a[k] > tmp) {
	                a[k + gap] = a[k]; // 将在a[i]前且比tmp的值大的元素向后移动一位
	                k -= gap;
	            }
	            a[k + gap] = tmp;
	        }
	    }
    }
}


void QuickSort(long int arr[], int low, int high) { // 快速排序
    if (low < high) {
        int i = low; // 左边界
        int j = high; // 右边界
        arr[low] = arr[low + (rand() << 15) % (high - low + 1)];
        // 为了防止数据过大出现卡死，所以需要在数组中随机出一个值来成为key值
        int k = arr[low]; // 设置的key值，也就是说，排完序后要变成这样[0~k] [k~n]
        while (i < j) {
            while (i < j && arr[j] >= k)     // 从右向左找第一个小于k的数
                j--;
            if (i < j)
                arr[i++] = arr[j]; // 如果找到了小于key的值，那么就交换
            while (i < j && arr[i] < k)      // 从左向右找第一个大于等于k的数
                i++;
            if (i < j)
                arr[j--] = arr[i]; // 如果找到了大于key的值，那么就交换
        }
        arr[i] = k; // 最终赋值给key成为[0~k] [k~n]
        // 递归调用
        QuickSort(arr, low, i - 1);     // 排序k左边
        QuickSort(arr, i + 1, high);    // 排序k右边
    }
}

void BubbleSort(long int a[], int n) { // 冒泡排序
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) { // 如果前一个数大于后一个数，就说明需要交换了
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void BuildHeap(long int a[], int k, int len)	{ //构造大堆
    a[0] = a[k];
    for (int i = 2 * k; i <= len; i *= 2) {     //沿值较大的子节点向下筛选
        if (i < len && a[i] < a[i + 1])         //如果它的左孩子的值小于右孩子的值
            i++;
        if (a[0] >= a[i])                       //如果根结点的值比左右孩子的最大值还要大或相等
            break;
        else {
            a[k] = a[i];                        //交换根结点与左右子孩子中最大值的结点
            k = i;                              //修改k的值，以便继续向下筛选
        }
    }
    a[k] = a[0];                                  //被筛选结点的值放入最终位置
    //对被交换的子女节点赋值 比如在2 9 8 6 5 7中9和2交换后，2需要和6再进行交换，最后只需要对6最开始的位置赋值2就行
}

void HeapSort(long int a[], int n) { // 大堆排序
		for(int i = n / 2; i > 0; i--)	{ //从最后一个父母节点开始，知道根节点
            BuildHeap(a,i,n);
        }
		for(int i = n; i> 1; i--) { //删除根节点后，重新构造堆
            int temp = a[1]; // 交换堆顶元素
            a[1] = a[i];
            a[i] = temp;
            BuildHeap(a,1,i-1);
        }
}

void data1_test() { // 六种排序分别对于对于data1数据集的测试
    printf("开始data1数据集的测试：\n");
    setbuf(stdout, NULL);
    read_file(PATH_DATA1); // 先读出data1数据集中的数据，赋值给num数组
    start = clock(); // 开始计时，单位是ms
    InsertSort(num, DATA1_NUM); // 调用插入排序
    end = clock(); // 计时结束
    out_put("插入排序", PATH_RESULT1, 11); // 输出进对应的文件中
    // 打印出相应的信息，计算出排序的耗时，单位是ms
    printf("插入排序排序data1的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA1); // 为了防止上一次的调用干扰后续排序，所以我们需要重新读出data1数据集中的数据
    start = clock();
    ShellSort(num, DATA1_NUM); // 调用希尔排序
    end = clock();
    out_put("希尔排序", PATH_RESULT1, DATA1_NUM);
    printf("希尔排序排序data1的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA1);
    start = clock();
    BubbleSort(num, DATA1_NUM);
    end = clock();
    out_put("冒泡排序", PATH_RESULT1, DATA1_NUM);
    printf("冒泡排序排序data1的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA1);
    start = clock();
    QuickSort(num, 0, DATA1_NUM);
    end = clock();
    out_put("快速排序", PATH_RESULT1, DATA1_NUM);
    printf("快速排序排序data1的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA1);
    start = clock();
    SelectSort(num, DATA1_NUM);
    end = clock();
    out_put("选择排序", PATH_RESULT1, DATA1_NUM);
    printf("选择排序排序data1的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA1);
    start = clock();
    HeapSort(num, DATA1_NUM);
    end = clock();
    out_put("堆排序", PATH_RESULT1, DATA1_NUM);
    printf("堆排序排序data1的耗时为：%.2fms\n", difftime(end, start));
    printf("结束data1数据集的测试\n\n");
}

void data2_test() { // 六种排序分别对于对于data2数据集的测试， 原理和data1的测试一致
    printf("开始data2数据集的测试：\n");
    setbuf(stdout, NULL);
    read_file(PATH_DATA2);
    start = clock();
    InsertSort(num, DATA2_NUM);
    end = clock();
    out_put("插入排序", PATH_RESULT2, DATA2_NUM);
    printf("插入排序排序data2的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA2);
    start = clock();
    ShellSort(num, DATA2_NUM);
    end = clock();
    out_put("希尔排序", PATH_RESULT2, DATA2_NUM);
    printf("希尔排序排序data2的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA2);
    start = clock();
    BubbleSort(num, DATA2_NUM);
    end = clock();
    out_put("冒泡排序", PATH_RESULT2, DATA2_NUM);
    printf("冒泡排序排序data2的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA2);
    start = clock();
    QuickSort(num, 0, DATA2_NUM);
    end = clock();
    out_put("快速排序", PATH_RESULT2, DATA2_NUM);
    printf("快速排序排序data2的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA2);
    start = clock();
    SelectSort(num, DATA2_NUM);
    end = clock();
    out_put("选择排序", PATH_RESULT2, DATA2_NUM);
    printf("选择排序排序data2的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA2);
    start = clock();
    HeapSort(num, DATA2_NUM);
    end = clock();
    out_put("堆排序", PATH_RESULT2, DATA2_NUM);
    printf("堆排序排序data2的耗时为：%.2fms\n", difftime(end, start));
    printf("结束data2数据集的测试\n\n");
}

void data3_test() { // 六种排序分别对于对于data3数据集的测试， 原理和data1的测试一致
    printf("开始data3数据集的测试：\n");
    setbuf(stdout, NULL);
    read_file(PATH_DATA3);
    start = clock();
    InsertSort(num, DATA3_NUM);
    end = clock();
    out_put("插入排序", PATH_RESULT3, DATA3_NUM);
    printf("插入排序排序data3的耗时为：%.2fms\n", difftime(end, start));
    
    read_file(PATH_DATA3);
    start = clock();
    ShellSort(num, DATA3_NUM);
    end = clock();
    out_put("希尔排序", PATH_RESULT3, DATA3_NUM);
    printf("希尔排序排序data3的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA3);
    start = clock();
    BubbleSort(num, DATA3_NUM);
    end = clock();
    out_put("冒泡排序", PATH_RESULT3, DATA3_NUM);
    printf("冒泡排序排序data3的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA3);
    start = clock();
    QuickSort(num, 0, DATA3_NUM);
    end = clock();
    out_put("快速排序", PATH_RESULT3, DATA3_NUM);
    printf("快速排序排序data3的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA3);
    start = clock();
    SelectSort(num, DATA3_NUM);
    end = clock();
    out_put("选择排序", PATH_RESULT3, DATA3_NUM);
    printf("选择排序排序data3的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA3);
    start = clock();
    HeapSort(num, DATA3_NUM);
    end = clock();
    out_put("堆排序", PATH_RESULT3, DATA3_NUM);
    printf("堆排序排序data3的耗时为：%.2fms\n", difftime(end, start));
    printf("结束data3数据集的测试\n\n");
}

void data4_test() { // 六种排序分别对于对于data4数据集的测试， 原理和data1的测试一致
    printf("开始data4数据集的测试：\n");
    setbuf(stdout, NULL);
    read_file(PATH_DATA4);
    start = clock();
    InsertSort(num, DATA4_NUM);
    end = clock();
    out_put("插入排序", PATH_RESULT4, DATA4_NUM);
    printf("插入排序排序data4的耗时为：%.2fms\n", difftime(end, start));
    
    read_file(PATH_DATA4);
    start = clock();
    ShellSort(num, DATA4_NUM);
    end = clock();
    out_put("希尔排序", PATH_RESULT4, DATA4_NUM);
    printf("希尔排序排序data4的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA4);
    start = clock();
    BubbleSort(num, DATA4_NUM);
    end = clock();
    out_put("冒泡排序", PATH_RESULT4, DATA4_NUM);
    printf("冒泡排序排序data4的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA4);
    start = clock();
    QuickSort(num, 0, DATA4_NUM);
    end = clock();
    out_put("快速排序", PATH_RESULT4, DATA4_NUM);
    printf("快速排序排序data4的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA4);
    start = clock();
    SelectSort(num, DATA4_NUM);
    end = clock();
    out_put("选择排序", PATH_RESULT4, DATA4_NUM);
    printf("选择排序排序data4的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA4);
    start = clock();
    HeapSort(num, DATA4_NUM);
    end = clock();
    out_put("堆排序", PATH_RESULT4, DATA4_NUM);
    printf("堆排序排序data4的耗时为：%.2fms\n", difftime(end, start));
    printf("结束data4数据集的测试\n\n");
}

void data5_test() { // 六种排序分别对于对于data5数据集的测试， 原理和data1的测试一致
    printf("开始data5数据集的测试：\n");
    setbuf(stdout, NULL);
    read_file(PATH_DATA5);
    start = clock();
    InsertSort(num, DATA5_NUM);
    end = clock();
    out_put("插入排序", PATH_RESULT5, DATA5_NUM);
    printf("插入排序排序data5的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA5);
    start = clock();
    ShellSort(num, DATA5_NUM);
    end = clock();
    out_put("希尔排序", PATH_RESULT5, DATA5_NUM);
    printf("希尔排序排序data5的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA5);
    start = clock();
    BubbleSort(num, DATA5_NUM);
    end = clock();
    out_put("冒泡排序", PATH_RESULT5, DATA5_NUM);
    printf("冒泡排序排序data5的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA5);
    start = clock();
    QuickSort(num, 0, DATA5_NUM);
    end = clock();
    out_put("快速排序", PATH_RESULT5, DATA5_NUM);
    printf("快速排序排序data5的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA5);
    start = clock();
    SelectSort(num, DATA5_NUM);
    end = clock();
    out_put("选择排序", PATH_RESULT5, DATA5_NUM);
    printf("选择排序排序data5的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA5);
    start = clock();
    HeapSort(num, DATA5_NUM);
    end = clock();
    out_put("堆排序", PATH_RESULT5, DATA5_NUM);
    printf("堆排序排序data5的耗时为：%.2fms\n", difftime(end, start));
    printf("结束data5数据集的测试\n\n");
}

void data6_test() { // 六种排序分别对于对于data6数据集的测试， 原理和data1的测试一致
    printf("开始data6数据集的测试：\n");
    setbuf(stdout, NULL);
    read_file(PATH_DATA6);
    start = clock();
    InsertSort(num, DATA6_NUM);
    end = clock();
    out_put("插入排序", PATH_RESULT6, DATA6_NUM);
    printf("插入排序排序data6的耗时为：%.2fms\n", difftime(end, start));
    
    read_file(PATH_DATA6);
    start = clock();
    ShellSort(num, DATA6_NUM);
    end = clock();
    out_put("希尔排序", PATH_RESULT6, DATA6_NUM);
    printf("希尔排序排序data6的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA6);
    start = clock();
    BubbleSort(num, DATA6_NUM);
    end = clock();
    out_put("冒泡排序", PATH_RESULT6, DATA6_NUM);
    printf("冒泡排序排序data6的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA6);
    start = clock();
    QuickSort(num, 0, DATA6_NUM);
    end = clock();
    out_put("快速排序", PATH_RESULT6, DATA6_NUM);
    printf("快速排序排序data6的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA6);
    start = clock();
    SelectSort(num, DATA6_NUM);
    end = clock();
    out_put("选择排序", PATH_RESULT6, DATA6_NUM);
    printf("选择排序排序data6的耗时为：%.2fms\n", difftime(end, start));

    read_file(PATH_DATA6);
    start = clock();
    HeapSort(num, DATA6_NUM);
    end = clock();
    out_put("堆排序", PATH_RESULT6, DATA6_NUM);
    printf("堆排序排序data6的耗时为：%.2fms\n", difftime(end, start));
    printf("结束data6数据集的测试\n\n");
}

int main() {
    // 设置随机数种子
    srand((unsigned int) time(NULL));
    int clean = 0;
    // 判断是否需要清空测试文件， 因为测试次数过多，同时我们的数据量比较大，会频繁的清空文件
    // 因此就写了一个判断用于是否清空文件
    if (!clean) {
        deal_data(); // 整体data数据集的处理，数据录入
        data1_test(); // 六种排序分别对data1数据集的测试
        data2_test(); // 六种排序分别对data2数据集的测试
        data3_test(); // 六种排序分别对data3数据集的测试
        data4_test(); // 六种排序分别对data4数据集的测试
        data5_test(); // 六种排序分别对data5数据集的测试
        data6_test(); // 六种排序分别对data6数据集的测试
    }else {
        clean_file(); // 清空测试文件中内容
    }
    return 0;
}
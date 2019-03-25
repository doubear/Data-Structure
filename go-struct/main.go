package main

import (
	"fmt"
	"math/rand"
	"regexp"
	"time"
)

type SortInterface interface {
	sort()
	maopaosort()
	kuaisu()
	charu()
}
type Sortor struct {
	name string
}

/*
(1)选择排序的基本思想是对待排序的记录序列进行n-1遍的处理，
第i遍处理是将L[i..n]中最小者与L[i]交换位置。
这样，经过i遍处理之后，前i个记录的位置已经是正确的了。
选择排序是不稳定的。算法复杂度是O(n ^2 )。
*/
func (sorter Sortor) sort(arry []int) {
	arrylength := len(arry)
	for i := 0; i < arrylength; i++ {
		min := i
		for j := i + 1; j < arrylength; j++ {
			if arry[j] < arry[min] {
				min = j
			}
		}
		t := arry[i]
		arry[i] = arry[min]
		arry[min] = t
	}
}

/*
(2)冒泡排序方法是最简单的排序方法。这种方法的基本思想是，
将待排序的元素看作是竖着排列的“气泡”，较小的元素比较轻，
从而要往上浮。在冒泡排序算法中我们要对这个“气泡”序列处理若干遍。
所谓一遍处理，就是自底向上检查一遍这个序列，
并时刻注意两个相邻的元素的顺序是否正确。如果发现两个相邻元素的顺序不对，
即“轻”的元素在下面，就交换它们的位置。显然，处理一遍之后，“最轻”的元素就浮到了最高位置；
处理二遍之后，“次轻”的元素就浮到了次高位置。在作第二遍处理时，
由于最高位置上的元素已是“最轻”元素，所以不必检查。一般地，第i遍处理时，
不必检查第i高位置以上的元素，因为经过前面i-1遍的处理，它们已正确地排好序。
冒泡排序是稳定的。算法时间复杂度是O(n ^2)
*/
func (sorter Sortor) maopaosort(arry []int) {
	arraylength := len(arry)
	for i := 0; i < arraylength; i++ {
		for j := 0; j < arraylength-i-1; j++ {
			if arry[j+1] < arry[j] {
				t := arry[j]
				arry[j] = arry[j+1]
				arry[j+1] = t
			}
		}
	}
}

/*(3)快速排序由C. A. R. Hoare在1962年提出。它的基本思想是：
通过一趟排序将要排序的数据分割成独立的两部分，
其中一部分的所有数据都比另外一部分的所有数据都要小，
然后再按此方法对这两部分数据分别进行快速排序，
整个排序过程可以递归进行，以此达到整个数据变成有序序列。
最理想情况算法时间复杂度O(nlog2n)，最坏O(n ^2)
*/
func (sorter Sortor) kuaisu(arry []int) {
	if len(arry) <= 1 {
		return
	}
	mid := arry[0]
	i := 1
	head, tail := 0, len(arry)-1
	for head < tail {
		if arry[i] > mid {
			arry[i], arry[tail] = arry[tail], arry[i]
			tail--
		} else {
			arry[i], arry[head] = arry[head], arry[i]
			head++
			i++
		}
		arry[head] = mid
		sorter.kuaisu(arry[:head])
		sorter.kuaisu(arry[head+1:])
	}
}

/*(4)插入排序
插入排序的基本思想是，经过i-1遍处理后,L[1..i-1]己排好序。
第i遍处理仅将L[i]插入L[1..i-1]的适当位置，使得L[1..i]又是排好序的序列。
要达到这个目的，我们可以用顺序比较的方法。首先比较L[i]和L[i-1]，
如果L[i-1]≤ L[i]，则L[1..i]已排好序，第i遍处理就结束了；
否则交换L[i]与L[i-1]的位置，继续比较L[i-1]和L[i-2]，
直到找到某一个位置j(1≤j≤i-1)，使得L[j] ≤L[j+1]时为止。
图1演示了对4个元素进行插入排序的过程，共需要(a),(b),(c)三次插入。
直接插入排序是稳定的。算法时间复杂度是O(n ^2) 。
*/
func (sorter Sortor) charu(arry []int) {
	arraylength := len(arry)
	for i, j := 1, 0; i < arraylength; i++ {
		temp := arry[i]
		for j = i; j > 0 && arry[j-1] > temp; j-- {
			arry[j] = arry[j-1]
		}
		arry[j] = temp
	}
}

//二分查找
func binarysearch(list []int, value int, left int, right int) int {
	mid := left + (right-left)/2
	if list[mid] < value {
		return binarysearch(list, value, mid+1, right)
	} else if list[mid] > value {
		return binarysearch(list, value, left, mid-1)
	}
	return mid
}
func binarysearch2(list []int, value int) int {
	left, right := 0, len(list)-1
	for left <= right {
		mid := left + (left+right)/2
		if list[mid] < value {
			left = mid + 1
		} else if list[mid] > value {
			right = mid - 1
		} else {
			return mid
		}
	}
	return -1
}

//菲波
//使用递归
func fibonacci(a int) int {
	if a == 1 || a == 2 {
		return 1
	}
	return fibonacci(a-1) + fibonacci(a-2)
}

//不使用递归
func fibonaccib(index int) int {
	if index == 1 || index == 2 {
		return 1
	}
	a, b := 1, 1
	for i := 3; i <= index; i++ {
		a, b = b, (a + b)
	}
	return b
}

//打印杨辉三角
func yanghui(lines int) {
	nums := []int{}
	for i := 0; i < lines; i++ {
		for j := 0; j < lines-i; j++ {
			fmt.Print(" ")
		}
		for j := 0; j < i+1; j++ {
			var length = len(nums)
			var value int
			if j == 0 || j == i {
				value = 1
			} else {
				value = nums[length-i] + nums[length-i-1]
			}
			nums = append(nums, value)
			fmt.Print(value, " ")
		}
		fmt.Println("")
	}
}

//正则表达式
func regx(a string) {
	reg := regexp.MustCompile("[\\{a-z}]+") //  [\\d]数字 +字符连接
	str1 := reg.FindAllString(a, -1)
	for _, v := range str1 {
		fmt.Println(v)
	}
	str2 := str1[0] + str1[1] + str1[2]
	fmt.Println(str2)
}

//生成随机数
func generatenum(start int, end int, count int) []int {
	if end < start || (end-start) < count {
		return nil
	}
	nums := make([]int, 0)
	//随机数生成器，加入时间戳保证每次生成的随机数不一样
	r := rand.New(rand.NewSource(time.Now().UnixNano()))
	for len(nums) < count {
		num := r.Intn((end - start)) + start
		//去重
		exist := false
		for _, v := range nums {
			if v == num {
				exist = true
				break
			}
		}
		if !exist {
			nums = append(nums, num)
		}
	}
	return nums
}

func main() {
	fmt.Println("算法总结")

	test := Sortor{name: "选择排序"}
	array := []int{6, 1, 3, 5, 8, 4, 2, 0, 9, 7}
	fmt.Println(array)
	//test.sort(array)//选择排序
	//test.maopaosort(array)//冒泡排序
	//test.kuaisu(array) //快速排序
	test.charu(array) //插入排序
	fmt.Println(array)
	//yanghui(5)//杨辉三角

	/*
		for i := 1; i <= 5; i++ {
			fmt.Print(fibonaccib(i), " ")
		}
	*/

	//str := "gtf43434gtf535gty"
	//regx(str)
	//fmt.Println(generatenum(10, 50, 5))

}

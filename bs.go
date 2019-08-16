package main

//连续最大子串和

func max(a, b int) int {
	var result int
	if a > b {
		result = a
	} else {
		result = b
	}
	return result
}
/*
func main() {
	var n int
	var value int
	fmt.Scanf("%d", &n)
	list := make([]int, n)
	dp := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &value)
		list[i] = value
	}

	var result int = list[0]
	dp[0] = list[0]

	for i := 1; i < n; i++ {
		value := list[i]
		dp[i] = max(value, value+dp[i-1])
		if result < dp[i] {
			result = dp[i]
		}
	}

	fmt.Println(result)
}

 */

//合并子串
/*
func main(){
	var a = [...]int{1,3,7,9}
	var b = [...]int{2,3,4,6,8,10}
	l:=len(a)+len(b)
	m:=0
	n:=0
	var c [10]int
	for i:= 0;i<l;i++ {
		if m<len(a)&&n<len(b){
			if a[m]<b[n]{
				c[i] = a[m]
				m++
			}else{
					c[i] = b[n]
					n++
			}
		}else if m == len(a){
			if n <len(b){
				c[i] = b[n]
				n++
			}
		}else if n==len(b){
			if m<len(a) {
				c[i] = a[m]
				m++
			}
		}
	}
	fmt.Println(c)

}

 */

//快排
/*
func  kuaisu(arry []int) {
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
		 kuaisu(arry[:head])
		 kuaisu(arry[head+1:])
	}
}

func main(){
	b :=[]int{3,5,2,6,8,4,2,1}
	kuaisu(b)
	fmt.Println(b)
}
 */

//回文子串
/*
var sum int = 0
func extend(s string,left,right int){
	for left>=0&&right<len(s)&&s[left]==s[right]{
		sum++
		left--
		right++
	}
}
func main(){
	var x string ="aabcb"
	l:=len(x)
	for i:=0;i<l;i++{
		extend(x,i,i)//记录不相邻的
		extend(x,i,i+1)//记录相邻的
	}
	fmt.Println(sum)
}
 */

//压缩字符串
/*
func main(){
	var x string
	fmt.Scan(&x)
	l := len(x)
	num := 0
	for i := 0;i<l;{
		start := i
		for x[i] == x[start]{
			num++
			i++
			if i == l{
				break
			}
		}
		if start<l{
			fmt.Printf("%d%c",num,x[start])
			num = 0
		}
	}
}
*/
/*
func main(){
	var n,x int
	var f [10100]int
	var num int
	f[0] = 1
	fmt.Scan(&n,&x)

	for i:=1;i<=n;i++ {
		fmt.Scan(&num)
		for j := x + 100; j >= 0; j-- {
			if f[j] == 1 {
				f[j+num] = 1
			}
		}
}
		for i:=x;i<=x+100;i++{
			if f[i]!=0 {
				fmt.Print(i)
				return
			}
		}
}
*/

//剑指offer-1
/*
func main(){
	var a = [...]int{2,3,5,4,3,2,6,7}
	n := 8
	var b [8]int
	for i:=0;i<n;i++{
		b[a[i]]++
	}

//空间o（2）时间o（2n）
	for j,num:=range b{
		if num>1 {
			fmt.Println(j, num)
		}
	}

//空间o（1）时间o（n2）
 for j,num:=range a{
 	for _,numb:=range a[j+1:]{
 		if num == numb{
 			fmt.Println(num)
		}
	}
 }
}
*/

//剑指offer-2 重建二叉树
/*
type Node struct {
	value int
	left *Node
	right *Node
}

func construnct(preorder,inorder []int) *Node{
	l := len(preorder)
	root := &Node{
		value : preorder[0],
	}
	leftlen := 0
	rightlen := 0
	for _,v := range inorder{
		if v == root.value{
			break
		}
		leftlen++
	}
	rightlen = l - leftlen -1
	if leftlen > 0{
		root.left = construnct(preorder[1:leftlen+1],inorder[0:leftlen])
	}
	if rightlen > 0{
		root.right = construnct(preorder[leftlen+1:],inorder[leftlen+1:])
	}
	return  root
}

func main()  {
	var a = []int{1,2,4,7,3,5,6,8}
	var b = []int{4,7,2,1,5,3,8,6}
	tree := construnct(a,b)
	preCatTree(tree)
	inCatTree(tree)
}

func preCatTree(t *Node) {
	fmt.Println(t.value)
	if t.left!=nil{
		preCatTree(t.left)
	}
	if t.right!=nil{
		preCatTree(t.right)
	}
}
func inCatTree(t *Node) {
	if t.left!=nil{
		inCatTree(t.left)
	}
	fmt.Println(t.value)
	if t.right!=nil{
		inCatTree(t.right)
	}
}
 */


//剑指 3 数组中的重复数字 o(n) o(1)
/*
func main(){
	b := []int{2,3,1,0,2,5,3}
	var n int
	//var b [7]int
	n = len(b)
	//for i:=0;i<n;i++{
	//	fmt.Scan(&b[i])
	//}
	for j := 0;j<n;j++{
			if b[j] != j {
					if b[j] == b[b[j]] {
						fmt.Println(b[j])
						return
					}
					b[b[j]], b[j] = b[j], b[b[j]]
			}
	}
}
 */

//剑指 4 二维数组中的查找
/*
func main(){
	a := [4][4]int{{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}}
	b := 3
	for i:=0;i<3;i++{
		if b>=a[0][i]&&b<a[0][i+1]{
			fmt.Println(i)
			for j:=0;j<4;j++{
				if b == a[j][i]{
					fmt.Println(i,j)
					return
				}
			}
		}
	}
		for j:=0;j<4;j++{
			if b == a[j][3]{
				fmt.Println(3,j)
				return
			}
		}
		fmt.Println(b)
}
 */

//剑指5 替换空格
/*
func main(){
	a := "we are happy"
	l := len(a)-1
	num := 0
	for _,i := range a{
		if i == ' '{
			num ++
		}
	}
	var b [30]byte
	for j:=l+3*num;j>=0;j--{
		if a[l] != ' '{
			b[j] = a[l]
			l--
			//fmt.Println(l,j)
		}else if a[l] == ' '{
			b[j] = '0'
			j--
			b[j] = '2'
			j--
			b[j] = '%'
			l--
		}
		if l==-1{
			break
		}
	}
	fmt.Println(string(b[:]))
}
 */

/*
//剑指6 链表 反转打印链表
type Node struct {
	Value interface{}
	Next *Node
}
func Insertnode(pos *Node){
	tmpnode :=new(Node)
	pos.Next = tmpnode
	tmpnode.Next = nil
}
func delnode(pos *Node, fvalue int)int{
    if pos.Value == fvalue||pos == nil {
		return 1
	}
	for pos.Next !=nil {
		if pos.Next.Value == fvalue {
			pos.Next = nil
		}
		pos = pos.Next
	}
    return 0
}
func Printres(pos *Node)  {
	if pos != nil{
		if pos.Next != nil{
			Printres(pos.Next)
		}
		fmt.Println(pos.Value)
	}
}
*/

//剑指7 重建二叉树

# Code-in-MarsCode
this repository is my exercise preparing for program development interview. Meanwhile I apply for the practice winter camp held by ByteDance. Code exercise is needed.


## 2024.11.17
1. idea：在进行刷题的时候，想到了一个idea。下面是我的prompt

>请你帮我写一个插件，任务是这样的：对谷歌浏览器网页上的代码问题（是在一个程序设计刷题平台上）进行爬取。当出现“回答正确”的字眼后，对代码编辑栏中的代码进行爬取，并对它们自动的整理成下列的格式，并在博客中自动发送<br>
<br>标题：即编程题的标题
<br>问题描述：即编程题的题干 
<br>注意事项与测试用例：题目给出的注意事项和测试用例
<br>我的代码：即我在文本编辑器中写的代码。

## 2024.11.19
1. 第二题的核心是双端队列。但是做题的思路应该是先简化成，没有滑窗K的情况，那么代码应该是对应的，（0，k）时，扫描最小值放入即可。但是当出现了载重（对应滑窗），就需要pop操作。不是所有最小值，都要加入。如何舍弃，是滑窗的一个智慧。具体代码操作见version3.
2. 第四题的核心是动态规划，新偶数态，由旧的偶数态和旧奇数态所决定。
3. 第五题的核心是对数据进行正确存放，以及调取。
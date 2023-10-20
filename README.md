 ### PUSH SWAP: sort a stack using a limited set of instruction


## the following are  only allowed instruction used to sort the stack A.

![image](https://github.com/alessiotucci/push_swap42/assets/116757689/982346fa-2879-46fb-823f-db90fd45c7a2)


![image](https://github.com/alessiotucci/push_swap42/assets/116757689/5dcc99a6-5395-4db2-b3ff-f95a69531a90)





 
 
 I started my project before Easter break, but since then I  didn't do much.
 After few tries I asked for help to some of my peers,
 and I noticed that most of them were using either the ["Mechanical Turk"](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)  or the quick sort.
 
 
 A 42  student  even did a [```full video tutorial```](https://youtu.be/OaG81sDEpVk) about the push  swap project, some  many were just  watching the tutorial instead of trying to come up with a creative solution.

<img width="242" alt="image" src="https://github.com/alessiotucci/push_swap42/assets/116757689/da30a652-c5da-445b-b276-ce099c80c739">


I have lost a lot of time to do this project, mainly because  I wanted to find my own way of sorting numbers, and sadly my method barely pass the minimum requirements, as you guys can see from the grade badge...
 [![atucci's 42 push_swap Score](https://badge42.vercel.app/api/v2/clfazuqz3001108jxp6bw1lum/project/3060049)](https://github.com/JaeSeoKim/badge42)

The code is  not well structured, and  is kind of messy, but spending so much time on sorting algorithm helped me have a better understanding of them, here there are some videos I have found very helpful when I switch over to the quick sort algorithm... 


Check [this website](https://www.toptal.com/developers/sorting-algorithms) to see algorithm visualization. 

### quick sort explained


<!-- BEGIN YOUTUBE-CARDS -->

[![this supposed to be the title](https://ytcards.demolab.com/?id=7h1s2SojIRw&ab_channel=AbdulBari)](https://youtu.be/7h1s2SojIRw)
[![QUICK SORT ALGORITHM](https://ytcards.demolab.com/?id=XE4VP_8Y0BU&ab_channel=Computerphile)](https://youtu.be/XE4VP_8Y0BU)
[![ALGORITHM](https://ytcards.demolab.com/?id=-qOVVRIZzao&ab_channel=AbdulBari)](https://youtu.be/-qOVVRIZzao) 


<!-- END YOUTUBE-CARDS -->


THOSE ARE FEW NOTES LEFT IN THE README.MB


```Now as 3rd of May I need to refactor all the code base to start working with list```


I soon realized that working with a list was simpler in a sense of moves, so I decided to not use int arrays;


```as 31 of May I need to use the quick sort algorithm since my selection sort is incredibly moves-expensive.```

# SELECTION SORT
I use the quick sort  only when pushing numbers from the stack A to the stack B, I stayed loyal to the selection sort when pushing  back from B to A;
 
| function name | Description | youtube links |
 | ----------------------------- | ------------------------------------------------- | ------------------------------------------------------- |
   | [`push_swap`](https://github.com/alessiotucci/push_swap42/blob/master/push_swap.c) | description | video|
 | [`Makefile`]() | description | video|
 | [`test_pushswap`]() | description | video|
  | [`incl folder`](https://github.com/alessiotucci/push_swap42/blob/master/incl/push_swap.h) | header file | video| 
  | [`libft`]() | description | video|


| source folder| Description |
 | ----------------------------- | ------------------------------------------------- | 
   | [`filling.c`](https://github.com/alessiotucci/push_swap42/blob/master/push_swap.c) |parsing argument from commmand line, both strings and digits|
   | [`sorting.c`](https://github.com/alessiotucci/push_swap42/blob/master/push_swap.c) |sorting element|
   | [`moves.c`](https://github.com/alessiotucci/push_swap42/blob/master/push_swap.c) |moves needed to move around numbers|
   | [`moves2.c`](https://github.com/alessiotucci/push_swap42/blob/master/push_swap.c) |moves needed to move around numbers|
        

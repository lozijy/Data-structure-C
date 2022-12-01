cmake_minimum_required(VERSION 3.23)
project(Data_structure_C C)

set(CMAKE_C_STANDARD 11)

include_directories(Arraylist)
include_directories(LinkedList/include)
include_directories(Queue)
include_directories(Stack)

add_executable(Data_structure_C
        Arraylist/arraylist.c
        Arraylist/arraylist.h
        Arraylist/arrayList_test.c
        LinkedList/code/linkedList.c
        LinkedList/code/linkedList_test.c
        LinkedList/code/solve_Josephus.c
        LinkedList/include/linkedList.h
        Queue/queue.c
        Queue/queue.h
        Queue/queue_test.c
        Stack/stack.c
        Stack/stack.h
        Stack/stack_test.c
        hashmap.c
        test.c)

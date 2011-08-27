//
//  LinkedList.h
//
//  Linked list will behave like a hash table (no collision resolution)
//  Will return node type U for key T
//
//  XcodeProjparkinglot
//
//  Created by Rohan Ambli on 8/20/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//



template <class T, class U>
class LinkedList
{
public:
    void AddNode(T key, U data);
    T GetNode(U data);
private:
}
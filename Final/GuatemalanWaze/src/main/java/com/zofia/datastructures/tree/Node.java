/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.zofia.datastructures.tree;

import com.zofia.dummyClasses.Track;

/**
 *
 * @author zofia
 */
public class Node {
    private int order;  //orden del arbol
    private int amount; //cantidad de keys en un nodo
    private Track[] keys;  //array de keys
    private Node[] children; //array de children
    private boolean leaf; //boolean que dice si es leaf o no
    private Node parent;  //nodo padre

    public Node(int order, Node parent) {
        this.order = order;
        this.parent = parent;
        keys = new Track[2*order - 1];
        children = new Node[2*order];
        leaf = true;
        amount = 0;
    }

    public Track getKeys(int index) {
        return keys[index];
    }
    
    public Node getChild(int index) {
        return children[index];
    }
    
    public void setKey(int index, Track key) {
        keys[index]= key;
    }
    
    public void setChild(int index, Node node) {
         children[index]= node;
    }
    
    public void setParent(Node parent) {
        this.parent = parent;
    }

    public boolean isLeaf() {
        return leaf;
    }

    public int getAmount() {
        return amount;
    }

    public int getOrder() {
        return order;
    }

    public Node getParent() {
        return parent;
    }

    public void setAmount(int amount) {
        this.amount = amount;
    }

    public void setLeaf(boolean leaf) {
        this.leaf = leaf;
    }

    public void setOrder(int order) {
        this.order = order;
    }
}

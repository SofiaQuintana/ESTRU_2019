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
public class BTree {
    private int order; // Tree order
    private Node root; // Tree root
    
    public BTree(int order) {
        this.order = order;
        this.root = new Node(order, null);
    }
    
    public Node search(Node root, Track key) {
        int i = 0; //searching index

        while(i < root.getAmount() && key.getId() > root.getKeys(i).getId()) {
            i++;
        }

        if(i <= root.getAmount() && key == root.getKeys(i)) {
            return root;
        }

        if(root.isLeaf()) {
            return null ;
        }
        else {
            return search(root.getChild(i),key);
        }
    }
    
    /*
     * funcion que divide el arbol una vez que ya supero la cantidad maxima de llaves
     * en una de sus hojas
    */
    public void divide(Node next, int i, Node previous) {
        Node temporal = new  Node(order,null);
        temporal.setLeaf(previous.isLeaf());
        temporal.setAmount(order-1);

        for(int j = 0; j < order - 1; j++) {
            temporal.setKey(j , previous.getKeys(j+order));
        }
        if(!previous.isLeaf()) {
            for(int k = 0; k < order; k++) {
                temporal.setChild(k, previous.getChild(k+order));
            }
        }
        previous.setAmount(order - 1);

        for(int j = next.getAmount(); j> i ; j--) {
            next.setChild(j+1, next.getChild(j));
        }
        next.setChild(i+1,temporal);

        for(int j = next.getAmount(); j> i; j--) {
            next.setKey(j+1,next.getKeys(j));
        }
        next.setKey(i,previous.getKeys(order-1));

        previous.setKey(order-1, null);

        for(int j = 0; j < order - 1; j++) {
            previous.setKey(j+order,null);
        }
        next.setAmount(next.getAmount()+1);
    }
    
    /*
     * insercion que se utiliza cuando una hoja aun puede 
     * recibir llaves en ella. 
    */
    public void leafInsertion(Node temporal, Track key) {
        int i = temporal.getAmount();

        if(temporal.isLeaf()) {
            while(i >= 1 && key.getId() < temporal.getKeys(i-1).getId()) {
                temporal.setKey(i,temporal.getKeys(i-1));
                i--;
            }
            temporal.setKey(i,key);
            temporal.setAmount(temporal.getAmount()+1);
        } else {
            int j = 0;
            while(j < temporal.getAmount()&& key.getId() > temporal.getKeys(j).getId()) {
                j++;
            }
            if(temporal.getChild(j).getAmount()== order*2 - 1) {
                divide(temporal,j,temporal.getChild(j));
                if(key.getId() > temporal.getKeys(j).getId()) {
                    j++;
                }
            }
            leafInsertion(temporal.getChild(j),key);
        }
    }

    
    public void insert(Node node, Track key) {
        if(node.getAmount()== 2*order - 1) {
            Node next = new  Node(order,null);
            this.root = next;
            next.setLeaf(false);
            next.setAmount(0);
            next.setChild(0,node);
            divide(next,0,node);
            leafInsertion(next, key);
        }
        else
            leafInsertion(node,key);
    }
    
    public void deleteKey(BTree tree, Track key) {
        Node node = new Node(order, null);
        node = search(tree.getRoot() ,key);

        if(node.isLeaf()&& node.getAmount()> order - 1) {
            int i = 0;
            while( key.getId()> node.getKeys(i).getId()) {
                i++;
            }
            for(int j = i; j < 2*order - 2; j++) {
                node.setKey(j,node.getKeys(j+1));
            }
            node.setAmount(node.getAmount()-1);
        }
        else {
            System.out.println("error");
        }
    }

    public Node getRoot() {
        return root;
    }

    public void setRoot(Node root) {
        this.root = root;
    }
    
    
}

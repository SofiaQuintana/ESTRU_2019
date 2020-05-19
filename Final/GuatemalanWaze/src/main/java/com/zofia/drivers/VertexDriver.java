/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.zofia.drivers;

import com.zofia.datastructures.graph.Edge;
import com.zofia.datastructures.graph.Vertex;
import com.zofia.dummyClasses.Route;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author zofia
 */
public class VertexDriver {
    private String origin;
    private String destination;
    private double vehicle, walking;
    private double fuel, wear;
    private List<Edge> edges;
    private List<Vertex> vertexes;
    private int index;

    public VertexDriver() {
        this.vertexes = new ArrayList<>();
        this.edges = new ArrayList<>();
        this.index = 0;
    }
    
    public void addNames(String name, int id) {
        switch (id) {
            case 1:
                origin = name;
                addVertex(name);
            break;
            case 2:
                destination = name;
                addVertex(name);
            break;
            default:
                System.out.println("restarting id...");
            break;
        }
    }
    
    public void addAmount(double amount, int id) {
        switch (id) {
            case 3:
                vehicle = amount;
            break;
            case 4:
                walking = amount;
            break;
            case 5:
                fuel = amount;
            break;
            case 6:
                wear = amount;
                addEdge();
            break;
            default:
                throw new AssertionError();
        }
    }
    
    private boolean verifyVertexName(String name) {
        boolean flag = false;
        if(!vertexes.isEmpty()) {
            for (int i = 0; i < vertexes.size(); i++) {
                Vertex vertex = vertexes.get(i);
                if(vertex.getName().equals(name)) {
                    flag = true;
                }
            }
        }
        return flag;
    }
    
    private void addVertex(String name) {
        if(verifyVertexName(name) == false) {
            vertexes.add(new Vertex(name, index));
            index++;
        }
    }
    
    private Vertex getVertex(String name) {
        for (int i = 0; i < vertexes.size(); i++) {
            Vertex vertex = vertexes.get(i);
            if(vertex.getName().equals(name)) {
                return vertex;
            }
        }
        return null;
    }
    
    private void addEdge() {
        Route route = new Route(origin, destination, vehicle, walking, fuel, wear);
        this.edges.add(new Edge(getVertex(route.getOrigin()), getVertex(route.getDestination()), route));
    }

    public List<Edge> getEdges() {
        return edges;
    }

    public List<Vertex> getVertexes() {
        return vertexes;
    }
}

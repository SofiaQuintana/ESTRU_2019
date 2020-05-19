/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.zofia.datastructures.graph;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author zofia
 */
public class Graph {
    private List<Vertex> vertexes = new ArrayList<>();
    private List<Edge> edges = new ArrayList<>();
    private int vertexSize;
    private int[][] diagraphAdjacency;
    private double[][] vehicleTime;
    private double[][] walkingTime;
    private double[][] fuelConsume;
    private double[][] wearConsume;
    private static final double INFINITE = Double.POSITIVE_INFINITY;

    public Graph(List<Vertex> vertexes, List<Edge> edges) {
        this.vertexes = vertexes;
        this.edges = edges;
        this.vertexSize = vertexes.size();
        this.diagraphAdjacency = new int[vertexSize][vertexSize];
        this.vehicleTime = new double[vertexSize][vertexSize];
        this.walkingTime = new double[vertexSize][vertexSize];
        this.fuelConsume = new double[vertexSize][vertexSize];
        this.wearConsume = new double[vertexSize][vertexSize];
        fillMatrix();
        fillMatrixWithValues();
    }
    
    public void fillMatrix() {
        for(int i = 0; i < vertexSize; i++) {
            for(int j = 0; j < vertexSize; j++) {
                diagraphAdjacency[i][j] = 0;
                vehicleTime[i][j] = INFINITE;
                walkingTime[i][j] = INFINITE;
                fuelConsume[i][j] = INFINITE;
                wearConsume[i][j] = INFINITE;
            }
        }
    }
    
    private int getVertexId(String name) {
        for(Vertex vertex : vertexes) {
            if(vertex.getName().equals(name)) {
                return vertex.getId();
            }
        }
        return -8;
    }
    
    public void fillMatrixWithValues() {
        int row, column;
        for(Edge edge : edges) {
            row = getVertexId(edge.getOrigin().getName());
            column = getVertexId(edge.getOrigin().getName());
            diagraphAdjacency[row][column] = 1;
            vehicleTime[row][column] = edge.getRoute().getVehicleTime();
            walkingTime[row][column] = edge.getRoute().getWalkingTime();
            fuelConsume[row][column] = edge.getRoute().getFuelConsume();
            wearConsume[row][column] = edge.getRoute().getPhysicalWear();
        } 
    }
    
    public int getDiagraphValue(int row, int column) {
        return this.diagraphAdjacency[row][column];
    }

    public List<Vertex> getVertexes() {
        return vertexes;
    }

    public void setVertexes(List<Vertex> vertexes) {
        this.vertexes = vertexes;
    }

    public List<Edge> getEdges() {
        return edges;
    }

    public void setEdges(List<Edge> edges) {
        this.edges = edges;
    }

    public int[][] getDiagraphAdjacency() {
        return diagraphAdjacency;
    }

    public double[][] getVehicleTime() {
        return vehicleTime;
    }

    public double[][] getWalkingTime() {
        return walkingTime;
    }

    public double[][] getFuelConsume() {
        return fuelConsume;
    }

    public double[][] getWearConsume() {
        return wearConsume;
    }
    
     public Vertex getVertex(int id){
        return vertexes.get(id);
    }
}

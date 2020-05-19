/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.zofia.drivers;

import com.zofia.datastructures.graph.Graph;
import com.zofia.datastructures.graph.Vertex;
import com.zofia.dummyClasses.Track;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author zofia
 */
public class GraphsDriver {
    private int[] unsettled;
    private double[] weights;
    private boolean[] settledVertices;
    private Track track;
    private List<Vertex> vertexes;
    private int size;
    private static final double POSITIVE = Double.POSITIVE_INFINITY;
    private static final double NEGATIVE = Double.NEGATIVE_INFINITY;

    public GraphsDriver(int size) {
        this.size = size;
        unsettled = new int[size];
        weights = new double[size];
        settledVertices = new boolean[size];
    }
    
    private int minimum() {
        double temporal = POSITIVE;
        int vertex = 0;
        for (int i = 0; i < size; i++) {
            if(!settledVertices[i] && (weights[i] <= temporal)) {
                temporal = weights[i];
                vertex = i;
            }
        }
        return vertex;
    }
    
    private int maximum() {
        double temporal = NEGATIVE;
        int vertex = 0;
        for (int i = 0; i < size; i++) {
            if(!settledVertices[i] && (weights[i] >= temporal)) {
                temporal = weights[i];
                vertex = i;
            }
        }
        return vertex;
    }
    
    public Track getMinimumTrack(int source, int destination, double[][] typeMatrix, Graph graph) {
        this.track = new Track(1);
        this.vertexes = new ArrayList<>();
        setInitialValues(source, typeMatrix);
        updateDistances(typeMatrix, minimum());
        createTrack(source, destination, graph);
        return getTrack(destination);
    }
    
    public Track getMaximumTrack(int source, int destination, double[][] typeMatrix, Graph graph) {
        double[][] temporal = new double[size][size];
        reinitializeIncomingValues(temporal, typeMatrix);
        this.track = new Track(2);
        vertexes = new ArrayList<>();
        setInitialValues(source, temporal);
        updatedDistances(temporal, maximum());
        createTrack(source, destination, graph);
        return getTrack(destination);
    }
    
    private void reinitializeIncomingValues(double[][] temporal, double[][] typeMatrix) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if(typeMatrix[i][j] == POSITIVE) {
                    temporal[i][j] = NEGATIVE;
                } else {
                    temporal[i][j] = typeMatrix[i][j];
                }
            }
        }
    }
    
    private void setInitialValues(int source, double[][] matrix) {
        for (int i = 0; i < size; i++) {
            settledVertices[i] = false;
            unsettled[i] = source;
            weights[i] = matrix[source][i];
        }
        settledVertices[source] = true;
        weights[source] = 0;
    }
    
    private void updatedDistances(double[][] matrix, int val) {
        for (int i = 1; i <= size; i++) {
            int value = val;
            settledVertices[value] = true;
            for (int j = 0; j < size; j++) {
                if(!settledVertices[j]) {
                    if((weights[value] + matrix[value][j]) > weights[value]) {
                        weights[value] = weights[value] + matrix[value][j];
                        unsettled[j] = value;
                    }
                }
            }
        }
    }
    
    private void updateDistances(double[][] matrix, int val) {
        for (int i = 1; i <= size; i++) {
            int value = val;
            settledVertices[value] = true;
            for (int j = 0; j < size; j++) {
                if(!settledVertices[j]) {
                    if((weights[value] + matrix[value][j]) < weights[value]) {
                        weights[value] = weights[value] + matrix[value][j];
                        unsettled[j] = value;
                    }
                }
            }
        }
    }
    
    public void createTrack(int origin, int destination, Graph graph){
        int previous = unsettled[destination];
        if (destination != origin){
            createTrack(origin, previous, graph); 
            vertexes.add(graph.getVertex(destination));
        }
        else{
            vertexes.add(graph.getVertex(origin));    
        }     
    }
        
   
    public Track getTrack(int destination){
        track.setTrackVertexes(vertexes);
        track.setDistance(weights[destination]);
        return track;
    } 
}

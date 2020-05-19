/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.zofia.dummyClasses;

import com.zofia.datastructures.graph.Vertex;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author zofia
 */
public class Track {
    private int id;
    private List<Vertex> trackVertexes;
    private double distance;

    public Track(int id) {
        this.id = id;
    }

    public Track(int id, List<Vertex> trackVertexes) {
        this.id = id;
        this.trackVertexes = new ArrayList<>();
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public List<Vertex> getTrackVertexes() {
        return trackVertexes;
    }

    public void setTrackVertexes(List<Vertex> trackVertexes) {
        this.trackVertexes = trackVertexes;
    }

    public double getDistance() {
        return distance;
    }

    public void setDistance(double distance) {
        this.distance = distance;
    }
    
}

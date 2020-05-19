/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.zofia.datastructures.graph;

import com.zofia.dummyClasses.Route;

/**
 *
 * @author zofia
 */
public class Edge {
    private Vertex origin;
    private Vertex destination;
    private Route route;

    public Edge(Vertex origin, Vertex destination, Route route) {
        this.origin = origin;
        this.destination = destination;
        this.route = route;
    }

    public Vertex getOrigin() {
        return origin;
    }

    public void setOrigin(Vertex origin) {
        this.origin = origin;
    }

    public Vertex getDestination() {
        return destination;
    }

    public void setDestination(Vertex destination) {
        this.destination = destination;
    }

    public Route getRoute() {
        return route;
    }

    public void setRoute(Route route) {
        this.route = route;
    }

}

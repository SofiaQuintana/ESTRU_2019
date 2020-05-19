/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.zofia.dummyClasses;

/**
 *
 * @author zofia
 */
public class Route {
    private String origin;
    private String destination;
    private double vehicleTime;
    private double walkingTime;
    private double fuelConsume;
    private double physicalWear;

    public Route(String origin, String destination, double vehicleTime, double walkingTime, double fuelConsume, double physicalWear) {
        this.origin = origin;
        this.destination = destination;
        this.vehicleTime = vehicleTime;
        this.walkingTime = walkingTime;
        this.fuelConsume = fuelConsume;
        this.physicalWear = physicalWear;
    }

    public String getOrigin() {
        return origin;
    }

    public void setOrigin(String origin) {
        this.origin = origin;
    }

    public String getDestination() {
        return destination;
    }

    public void setDestination(String destination) {
        this.destination = destination;
    }

    public double getVehicleTime() {
        return vehicleTime;
    }

    public void setVehicleTime(double vehicleTime) {
        this.vehicleTime = vehicleTime;
    }

    public double getWalkingTime() {
        return walkingTime;
    }

    public void setWalkingTime(double walkingTime) {
        this.walkingTime = walkingTime;
    }

    public double getFuelConsume() {
        return fuelConsume;
    }

    public void setFuelConsume(double fuelConsume) {
        this.fuelConsume = fuelConsume;
    }

    public double getPhysicalWear() {
        return physicalWear;
    }

    public void setPhysicalWear(double physicalWear) {
        this.physicalWear = physicalWear;
    }
    
}

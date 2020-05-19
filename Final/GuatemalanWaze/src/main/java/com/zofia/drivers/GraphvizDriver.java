/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.zofia.drivers;

import com.zofia.datastructures.graph.Graph;
import com.zofia.datastructures.graph.Vertex;
import java.io.IOException;

/**
 *
 * @author zofia
 */
public class GraphvizDriver {
    private static final String DIAGRAPH_OPENING = "digraph G{ \n";
    private static final String DIAGRAPH_CLOSING = "}";
    
    //CREAR IMAGEN
    public void createImage(String name){
        try {
            String [] cmd = {"dot","-Tpng","-o", "image.png", "image.dot"};
            Runtime.getRuntime().exec(cmd); 
        } 
        catch (IOException ex) {
            System.out.println("Error al ejecutar comando");
        }
    }
    
    //AGREGAR TODOS LOS VERTICES CON SU RESPECTIVO COLOR.
    private String addVertices(Graph graph, String originName, String destinationName, String currentName){
        String text = "";
        for(Vertex vertex : graph.getVertexes()){
            if(vertex.getName().equals(currentName)){
                text = text + "\t" + vertex.getName() + "[color=blue, style=filled, fontcolor=white];\n";
            }
            else if(vertex.getName().equals(originName)){
                text = text + "\t" + vertex.getName() + "[color=lightblue, style=filled, fontcolor=white];\n";
            }
            else if(vertex.getName().equals(destinationName)){
                text = text + "\t" + vertex.getName() + "[color=green, style=filled, fontcolor=black];\n";
            }
            else{
                text = text + "\t" + vertex.getName() + ";\n";
            }
        }
        return text;
    }
    
    //AGREGAR HEADER DEL ARCHIVO.
    private String setHeader(){
        String text = DIAGRAPH_OPENING;
        return text;
    }
    
    //AGREGA LAS ARISTAS CORRESPONDIENTES.
    private String addEdges(Graph graph, double[][] matrix){
        String text = "";
        for(int i = 0; i < graph.getEdges().size(); i++){
            for(int j = 0; j < graph.getEdges().size(); j++){
                if(graph.getDiagraphValue(i, j) == 1){
                    text = text + "\t" + graph.getVertexes().get(i).getName() + "->" + 
                            graph.getVertexes().get(j).getName() + " [label=\""+ matrix[i][j] +"\"];\n";
                }
            }
        }
        return text;
    }
    
    
}

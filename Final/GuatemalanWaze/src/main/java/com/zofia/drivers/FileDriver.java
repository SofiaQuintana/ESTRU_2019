/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.zofia.drivers;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 *
 * @author zofia
 */
public class FileDriver {
    private FileReader reader;
    private BufferedReader buffer;
    private String line;
    private String fileContent;

    public String readInputFile(String path) throws FileNotFoundException, IOException{
        this.fileContent = "";
        reader = new FileReader(new File(path));
        buffer = new BufferedReader(reader);
        while((this.line = buffer.readLine()) != null) {
            this.fileContent += line + "\n";
        }   
        return fileContent;
    }

    public void writeFile(String data, String name){;
        FileWriter writer;
        BufferedWriter bufferWriter;
	try {
            writer = new FileWriter("image.dot");
            bufferWriter = new BufferedWriter(writer);
            bufferWriter.write(data);
            bufferWriter.close();
	} catch (IOException ex) {
            System.out.println("Mensaje de la excepción: " + ex.getMessage());
        }
    }
    
}

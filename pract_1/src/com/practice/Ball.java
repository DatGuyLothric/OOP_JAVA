package com.practice;

import java.lang.*;

public class Ball {
    private String color;
    private int size;

    public Ball(String c_color, int c_size) {
        color = c_color;
        size = c_size;
    }

    public Ball(int c_size) {
        color = "White";
        size = c_size;
    }

    public Ball() {
        color = "White";
        size = 50;
    }

    public void setColor(String c_color) {
        color = c_color;
    }

    public void setSize(int c_size) {
        size = c_size;
    }

    public String getColor() {
        return color;
    }

    public int getSize() {
        return size;
    }

    public String toString() {
        return color + " ball, " + size + " size!\n";
    }

}

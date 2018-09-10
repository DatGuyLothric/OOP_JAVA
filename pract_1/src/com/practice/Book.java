package com.practice;

import java.lang.*;

public class Book {
    private String title;
    private String autor;
    private int pages_num;

    public Book(String c_title, String c_autor, int c_pages_num) {
        title = c_title;
        autor = c_autor;
        pages_num = c_pages_num;
    }

    public Book(String c_title, String c_autor) {
        title = c_title;
        autor = c_autor;
        pages_num = 100;
    }

    public Book() {
        title = "Great";
        autor = "Man";
        pages_num = 100;
    }

    public void setTitle(String c_title) {
        title = c_title;
    }

    public void setAutor(String c_autor) {
        autor = c_autor;
    }

    public void setPagesNum(int c_pages_num) {
        pages_num = c_pages_num;
    }

    public String getTitle() {
        return title;
    }

    public String getAutor() {
        return autor;
    }

    public int getPagesNum() {
        return pages_num;
    }

    public String toString() {
        return autor + " '" + title + "', " + pages_num + " pages!\n";
    }

}

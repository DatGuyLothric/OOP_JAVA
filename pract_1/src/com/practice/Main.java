package com.practice;

public class Main {

    public static void main(String[] args) {
        System.out.println("Ex #1:");

        Ball ball_1 = new Ball ("Red", 47);
        Ball ball_2 = new Ball (100);
        Ball ball_3 = new Ball ();

        ball_2.setColor("Blue");
        ball_3.setColor("Black");
        ball_3.setSize(30);

        String out = ball_1.toString();
        System.out.println(out);

        System.out.println("Ex #2:");

        Book book_1 = new Book ("Gold", "Grumble", 56);
        Book book_2 = new Book ("Adventure", "Freedler");
        Book book_3 = new Book ();

        book_3.setTitle("Nemesis");
        book_3.setAutor("Redler");
        book_3.setPagesNum(550);

        String out_2 = book_3.toString();
        System.out.println(out_2);

    }
}

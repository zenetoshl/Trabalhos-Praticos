package com.company;
import java.util.Scanner;

public class quest1 {

    public static void main(String[] args) {
	// questao 1:
        Scanner s = new Scanner(System.in);
        int altura = s.nextInt();
        for(int i = 1; i <= altura; i++){
            for(int j = 1;j <= i; j++){
                System.out.print("*");
            }
            System.out.println();
        }
    }
}

package com.company;
import java.util.Scanner;

public class quest2{

    public static void main(String[] args) {
	// questao 2:
        Scanner s = new Scanner(System.in);
        System.out.println("digite o ano do seu nascimento: ");
        int nascimento = s.nextInt();
        System.out.println("digite o ano atual: ");
        int atual = s.nextInt();
        System.out.println("Idade: "+ (atual-nascimento));
    }
}

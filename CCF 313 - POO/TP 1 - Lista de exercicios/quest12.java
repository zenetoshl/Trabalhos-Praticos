package com.company;
import com.sun.scenario.effect.impl.sw.sse.SSEBlend_SRC_OUTPeer;

import java.util.Scanner;
import java.util.Random;

public class quest12 {

    public static void main(String[] args) {
	// questao 12:
        Random r  = new Random();
        Scanner s = new Scanner(System.in);
        int num = r.nextInt(101);
        int cont = 0;
        while (true){
            System.out.print("Digite sua tentativa: ");
            int tentativa = s.nextInt();
            cont++;
            if (tentativa == num){
                System.out.println("Parabens!! " + num + " é o numero secreto!!");
                System.out.println("Numero de tentativas: "+ cont);
                break;
            }else if (tentativa < num){
                System.out.println(tentativa + " é menor que o numero secreto!");
                System.out.println("Numero de tentativas: " + cont);
            }else if (tentativa > num){
                System.out.println(tentativa + " é maior que o numero secreto!");
                System.out.println("Numero de tentativas: " + cont);
            }
        }


    }
}

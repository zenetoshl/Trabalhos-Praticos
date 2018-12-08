package com.company;
import java.util.Scanner;

public class quest9 {

    public static void main(String[] args) {
	// questao 9:
        int soma = 0, maior = 0, menor = 0, par = 0, impar = 0;
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();

        for (int i = 0; i < n;i++){
            int x = s.nextInt();
            if(i == 0){
                maior = x;
                menor = x;
            } else {
                if (x > maior){
                    maior = x;
                }
                if (x < menor){
                    menor = x;
                }
            }
            soma+=x;
            if (x % 2 == 0)
                par++;
            else
                impar++;
        }
        Double media = (double)soma/(double)n;
        System.out.println("Menor: "+menor+" Maior: "+maior);
        System.out.println("Pares: "+par+ " Impares: "+ impar);
        System.out.println("Media: " + media);
    }
}

package com.company;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class quest13 {

    public static void main(String[] args) throws IOException {
	// questao 13:
        File file = new File("paciente.txt");
        Scanner s = new Scanner(file);
        String nome,sexo;
        double altura, peso;
        int idade, numPacientes = 0;
        int idadeH = 0, numH = 0, numM = 0, maiorID = 0, jovens = 0, mulheresAP = 0;
        double menAlt = 0;
        String velho = "NULL", baixa = "NULL";
        s.useDelimiter("\n");
        while(s.hasNext()){
            numPacientes++;
            nome = s.next();
            sexo = s.next();
            peso = s.nextDouble();
            idade = s.nextInt();
            altura = s.nextDouble();

            if(idade >= 18 && idade <= 25){
                jovens++;
            }

            if(sexo.equals("Feminino")){
                numM++;
                if(numM == 1) {
                    baixa = nome.substring(0);
                    menAlt = altura;
                }else if (menAlt > altura){
                    baixa = nome.substring(0);
                    menAlt = altura;
                }
                if (peso > 70 && altura >= 1.60 && altura <= 1.70){
                    mulheresAP++;
                }
            }else {
                if (numPacientes == 0) {
                    velho = nome.substring(0);
                    maiorID = idade;
                } else if (idade > maiorID) {
                    velho = nome.substring(0);
                    maiorID = idade;
                }
                numH++;
                idadeH += idade;
            }
        }
        System.out.println("Media de idade dos homens: " + (idadeH/numH));
        System.out.println("Nome do homem mais velho: " + velho);
        System.out.println("Nome da mulher mais baixa: " + baixa);
        System.out.println("Numero de pacientes: " + numPacientes);
        System.out.println("Numero de mulheres com altura entre 1,60 e 1,70 e peso acima de 70kg: " + mulheresAP);
        System.out.println("Numero de pacientes com idade entre 18 e 25 anos: " + jovens);
    }
}

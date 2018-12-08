package com.company;
import java.util.Scanner;

public class quest7 {

    public static void main(String[] args) {
	// questao 7:
        int ind1,ind2,hora,min,sec,hora2,min2,sec2 ;
        Scanner s = new Scanner(System.in);

        System.out.println("digite um horario no segunte formato (H:M:S): ");
        
        String horario= s.next();
        ind1 = horario.indexOf(":");
        String Buff = horario.substring((ind1+1));
        ind2 = Buff.indexOf(":");
        String H = horario.substring(0,ind1);
        String M = Buff.substring(0,(ind2));
        String S = horario.substring((ind2+ind1+2));
        hora = Integer.parseInt(H);
        min = Integer.parseInt(M);
        sec = Integer.parseInt(S);

        sec = sec + (min*60) + (hora*60*60);
        System.out.println("digite outro horario no segunte formato (H:M:S): ");

        horario = s.next();
        ind1 = horario.indexOf(":");
        Buff = horario.substring((ind1+1));
        ind2 = Buff.indexOf(":");
        H = horario.substring(0,ind1);
        M = Buff.substring(0,(ind2));
        S = horario.substring((ind2+ind1+2));
        hora2 = Integer.parseInt(H);
        min2 = Integer.parseInt(M);
        sec2 = Integer.parseInt(S);

        sec2 = sec2 + (min2*60) + (hora2*60*60);
        if(sec2 > sec)
            sec = sec2 - sec;
        else
            sec = sec - sec2;
        hora = sec / (60*60);
        sec = sec - (hora*60*60);
        min = sec / 60;
        sec = sec - (min*60);
        System.out.println("resultado: "+hora+":"+min+":"+sec);

    }
}

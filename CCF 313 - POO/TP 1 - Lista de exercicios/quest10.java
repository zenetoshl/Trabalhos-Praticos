package com.company;

import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class quest10 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String ent;
        ArrayList array = new ArrayList();
        while (true){
            ent = s.next();
            if ("fim".equals(ent)){
                break;
            }else{
                array.add(ent);
            }
        }
        Collections.sort(array);
        System.out.println("numeros ordenados: "+ array);
    }
}

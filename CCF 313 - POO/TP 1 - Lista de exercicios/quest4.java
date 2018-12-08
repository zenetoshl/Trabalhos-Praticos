package com.company;
import java.util.Scanner;

public class quest4 {

    public static void main(String[] args) {
	// questao 4:
        Scanner s = new Scanner(System.in);
        System.out.println("Entre com seu salario bruto: ");
        Double salario = s.nextDouble();
        System.out.println("entre com os descontos do seu salario: ");
        Double desconto = s.nextDouble();
        System.out.println("entre com o pedido de emprestimo: ");
        Double pedido = s.nextDouble();
        salario = salario - desconto;
        if (pedido <= (salario*0.3)){
            System.out.println("emprestimo aprovado!");
        } else{
            System.out.println("emprestimo reprovado!");
        }
    }
}

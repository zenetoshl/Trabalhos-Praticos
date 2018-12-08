package br.ufv.caf.grafos;

import java.io.IOException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
        int escolha = 99;
        int aux, auy;
        Scanner scanner = new Scanner(System.in);
        Grafo g = new Grafo("aplicareal.txt");

        System.out.println("  " +g.isEuleriano());
        //System.out.println("  " + g.buscaLargura(0,"retorno"));
        System.out.println("  " + g.hasCicloNegativo());


        while (escolha != 0) {
            System.out.println("1-ordem do grafo");
            System.out.println("2-tamanho do grafo");
            System.out.println("3-vizinhos dado um vertice");
            System.out.println("4-grau vertice fornecido");
            System.out.println("5-grafo e bipartido");
            System.out.println("6-vertice e articulacao");
            System.out.println("7-verifica ponte");
            System.out.println("8-distancia  minima entre vertices");
            System.out.println("9-caminho minimo entre vertices");
            System.out.println("10-numero de componentes conexas");
            System.out.println("");
            System.out.println("");
            System.out.println("0-Encerra");
            escolha = scanner.nextInt();
            switch (escolha) {
                case 0:
                    System.out.println("Encerrando...");
                    break;

                case 1:
                    System.out.println("  " + g.getOrdem());
                    break;

                case 2:
                    System.out.println("  " + g.getTamanho());
                    break;

                case 3:
                System.out.println("entre com o vertice");
                aux = scanner.nextInt ();
                System.out.println("  " + g.getVizinhosVertice(aux - 1));

                    break;

                case 4:
                System.out.println("entre com o vertice");
                 aux = scanner.nextInt ();
                System.out.println("  " + g.getVizinhosVertice(aux - 1).size());


                    break;

                case 5:
                    System.out.println("  " + g.isBipartido());
                    break;

                case 6:
                    System.out.println("entre com o vertice");
                    aux = scanner.nextInt();
                    System.out.println("  " + g.isArticulacao(aux - 1));
                    break;

                case 7:
                    System.out.println("entre com o vertices");
                    aux = scanner.nextInt();
                    auy = scanner.nextInt();
                    System.out.println("  " + g.isPonte(aux - 1, auy - 1));
                    break;


                case 8:
                    System.out.println("entre com o vertices");
                    aux = scanner.nextInt();
                    auy = scanner.nextInt();
                    System.out.println("  " + g.distanciaMinima(aux - 1, auy - 1));
                    break;


                case 9:
                    System.out.println("entre com o vertices");
                    aux = scanner.nextInt();
                    auy = scanner.nextInt();
                    System.out.println("  " + g.caminhoMinimo(aux - 1, auy - 1));
                    break;
                case 10:

                    System.out.println("  " + g.numComponentesConexas());
                    break;


            }
        }
    }
}

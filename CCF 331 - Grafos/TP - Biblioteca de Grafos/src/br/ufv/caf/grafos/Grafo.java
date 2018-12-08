package br.ufv.caf.grafos;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;



public class Grafo {
    private double matrizValores[][];
    private int ordem;
    private int tamanho;
    private final double Infinity = Double.POSITIVE_INFINITY;
    private double[][] L;
    private int[][] R;

    public double[][] getL() {
        return L;
    }

    public int[][] getR() {
        return R;
    }

    class V{
        int indice;
        private boolean marcado;
        int cor;
        int graus;

        V (int indice){
            this.indice = indice;
            marcado = false;
            cor = 0;
            graus = getOrdemVertice(indice);
        }

        public void marca(){
            this.marcado = true;
        }

        public boolean isMarcado(){
            return this.marcado;
        }

        public String toString(){
            return  " " + (indice+1);
        }
    }
    class A{
        int src;
        int dst;
        double peso;

        A (int a, int b) {
            int s,d;
            if (a < b){
                s = a;
                d = b;
            } else {
                s = b;
                d = a;
            }
            this.src = s;
            this.dst = d;
            this.peso = 1;
        }

        A (int a, int b, double peso) {
            int s,d;
            if (a < b){
                s = a;
                d = b;
            } else {
                s = b;
                d = a;
            }
            this.src = s;
            this.dst = d;
            this.peso = peso;
        }

        @Override
        public String toString() {
            return "(" + (src+1) + ", " + (dst+1) + ')';
        }
    }


    public Grafo(String nome) throws IOException {
        int v1, v2;
        double peso;
        Scanner s = new Scanner(new File(nome));

        this.tamanho = s.nextInt();
        this.ordem = 0;

        matrizValores = new double[tamanho][tamanho];

        for(int i = 0; i < matrizValores.length; i++){
            for(int j = 0; j < matrizValores[i].length; j++){
                matrizValores[i][j] = 0;
            }
        }

        while (s.hasNext()) {
            this.ordem++;
            v1 = s.nextInt();
            v2 = s.nextInt();
            peso = s.nextDouble();

            matrizValores[v1 - 1][v2 - 1] = (double)peso;
            matrizValores[v2 - 1][v1 - 1] = (double)peso;
        }
        floydWarshall();
    }

    private Grafo(double[][] m, int src, int dst){
        matrizValores = new double[m.length][m.length];
        for(int i = 0; i < matrizValores.length; i++){
            for(int j = 0; j < matrizValores[i].length; j++){
                matrizValores[i][j] = m[i][j];
            }
        }
        tamanho = m.length;
        ordem = 0;
        matrizValores[src][dst] = 0;
        matrizValores[dst][src] = 0;
    }

    public LinkedList<Integer> getVizinhosVertice(int indice){
        LinkedList<Integer> lista = new LinkedList<>();
        for(int i = 0; i < tamanho; i++){
            if(matrizValores[indice][i] != 0){
                lista.add(i);
            }
        }
        return lista;
    }

    public LinkedList<Integer> getVizinhosVertice(int indice, int exc){
        LinkedList<Integer> lista = new LinkedList<>();
        for(int i = 0; i < tamanho; i++){
            if(matrizValores[indice][i] != 0 && i != exc){
                lista.add(i);
            }
        }
        return lista;
    }

    public int getOrdemVertice(int indice){
        int contador = 0;
        for(int i = 0; i < tamanho; i++){
            if(matrizValores[indice][i] != 0){
                contador++;
            }
        }
        return contador;
    }

    public int getOrdem() { return ordem; }

    public int getTamanho() { return tamanho; }

    public void imprimeMatriz(){
        for (int i = 0; i < tamanho; i++){
            for (int j = 0; j < tamanho; j++) {
                System.out.printf(" %5.2f", matrizValores[i][j]);
            }
            System.out.println();
        }
    }

    public LinkedList<A> buscaLargura(int indice, String op){
        V vertice;
        LinkedList<Integer> vizinhos;
        LinkedList<A> listaRetorno = new LinkedList<>();
        LinkedList<A> listaVisitadas = new LinkedList<>();
        LinkedList<V> listaVertices = new LinkedList<>();
        LinkedList<V> Q = new LinkedList<>();
        for(int i = 0; i < tamanho; i++)
            listaVertices.add(new V(i));
        listaVertices.get(indice).marca();
        Q.add(listaVertices.get(indice));
        while(!Q.isEmpty()){
            vertice = Q.getFirst();
            Q.remove(Q.getFirst());
            vizinhos = getVizinhosVertice(vertice.indice);
            for(Integer i : vizinhos){
                if(!listaVertices.get(i).isMarcado()){
                    listaVertices.get(i).marca();
                    Q.add(listaVertices.get(i));
                    listaVisitadas.add(new A(vertice.indice, listaVertices.get(i).indice));
                } else if (comparaAresta(listaVisitadas, new A(vertice.indice, listaVertices.get(i).indice))
                            && comparaAresta(listaRetorno, new A(vertice.indice, listaVertices.get(i).indice))){
                    listaRetorno.add(new A(vertice.indice, listaVertices.get(i).indice));
                }
            }
        }
        if(op.equals("visitadas"))
            return listaVisitadas;
        else
        return listaRetorno;
    }

    private boolean comparaAresta (LinkedList<A> lista, A aresta){
        for(A a : lista){
            if(a.dst == aresta.dst && a.src == aresta.src)
                return false;
        }
        return true;
    }

    public LinkedList<V> buscaProfundidade(int indice){
        LinkedList<V> lista = new LinkedList<>();
        LinkedList<V> visitados = new LinkedList<>();
        for(int i = 0; i < tamanho; i++)
            lista.add(new V(i));

        BP(visitados ,lista, indice);

        return visitados;
    }

    private void BP(LinkedList<V> visitados,LinkedList<V> lista, int indice){
        LinkedList<Integer> vizinhos;
        visitados.add(lista.get(indice));
        lista.get(indice).marca();
        vizinhos = getVizinhosVertice(indice);
        for(Integer i: vizinhos){
            if(!lista.get(i).isMarcado()){
                BP(visitados, lista, i);
            }
        }
    }

    public boolean isBipartido(){
        V vertice;
        LinkedList<Integer> vizinhos;
        LinkedList<V> listaVertices = new LinkedList<>();
        LinkedList<V> Q = new LinkedList<>();
        int cor = 1;
        for(int i = 0; i < tamanho; i++)
            listaVertices.add(new V(i));
        listaVertices.get(0).cor = cor;
        Q.add(listaVertices.get(0));
        while(!Q.isEmpty()) {
            vertice = Q.getFirst();
            Q.remove(Q.getFirst());
            cor = vertice.cor * -1;
            vizinhos = getVizinhosVertice(vertice.indice);
            for (Integer i : vizinhos) {
                if (listaVertices.get(i).cor == 0) {
                    listaVertices.get(i).cor = cor;
                    Q.add(listaVertices.get(i));
                } else if (listaVertices.get(i).cor != cor)
                    return false;
            }
        }
        return true;
    }

    private int buscaConexos(LinkedList<V> listaVertices){
        V vertice;
        V aux;
        boolean ap = false;
        int apagado = -1;
        int cont = 0;
        int k = 0;
        for(V v : listaVertices){
            if (v.indice != k){
                ap = true;
                apagado = k;
            }
            k++;
        }
        LinkedList<Integer> vizinhos;
        LinkedList<V> Q = new LinkedList<>();
        LinkedList<V> lista = new LinkedList<>();
        cont++;
        listaVertices.getFirst().marca();
        Q.add(listaVertices.getFirst());
        lista.add(listaVertices.getFirst());
        while(listaVertices.size() != lista.size()) {
            while (!Q.isEmpty()) {
                vertice = Q.getFirst();
                Q.remove(Q.getFirst());
                if(ap) {
                    vizinhos = getVizinhosVertice(vertice.indice, apagado);
                } else vizinhos = getVizinhosVertice(vertice.indice, apagado);
                for (Integer i : vizinhos) {
                    aux = marcaVertice(listaVertices, i);
                    if (aux != null) {
                        Q.add(aux);
                        lista.add(aux);
                    }
                }
            }
            for(V v : listaVertices){
                if(!lista.contains(v)){
                    Q.add(v);
                    v.marca();
                    lista.add(v);
                    cont++;
                    break;
                }
            }
        }
        return cont;
    }

    private V marcaVertice(LinkedList<V> lista, int vizinho){
        for(V v : lista){
            if(vizinho == v.indice && !v.isMarcado()) {
                v.marca();
                return v;
            }
        }
        return null;
    }


    public boolean isArticulacao (int indice){
        LinkedList<V> listaVertices = new LinkedList<>();
        LinkedList<V> listaReduzida = new LinkedList<>();
        V aux;
        int a, b;
        for(int i = 0; i < tamanho; i++) {
            listaVertices.add(new V(i));
            listaReduzida.add(new V(i));
        }
        listaReduzida.remove(listaReduzida.get(indice));
        a = buscaConexos(listaVertices);
        b = buscaConexos(listaReduzida);

        return(b > a);
    }

    public boolean isPonte (int src, int dst){
        int a, b;
        Grafo g = new Grafo(matrizValores, src, dst);
        a = g.numComponentesConexas();
        b = numComponentesConexas();
        return (a > b);
    }

    public int numComponentesConexas (){
        LinkedList<V> lista = new LinkedList<>();
        for(int i = 0; i < tamanho; i++){
            lista.add(new V(i));
        }
        return buscaConexos(lista);
    }

    public boolean hasCicloNegativo (){
        for(int i = 0; i < tamanho; i++){
            if(R[i][i] < 0){
                return true;
            }
        }
        return false;
    }

    private double W(int i,int j){
        if(i == j)
            return 0;
        else if (matrizValores[i][j] != 0)
            return matrizValores[i][j];
        else
            return Infinity;
    }


    private void floydWarshall(){
        this.L = new double[tamanho][tamanho];
        this.R = new int[tamanho][tamanho];
        //inicializa as matrizes
        for(int i = 0; i < tamanho; i++){
            for(int j = 0; j < tamanho; j++){
                L[i][j] = W(i, j);
                if(L[i][j] == Infinity)
                    R[i][j] = -1;
                else R[i][j] = i;
            }
        }
        for(int k = 0; k < tamanho; k++){
            for(int i = 0; i < tamanho; i++) {
                for (int j = 0; j < tamanho; j++) {
                    double aux = (L[i][k] + L[k][j]);
                    if(L[i][j] > aux){
                        L[i][j] = aux;
                        R[i][j] = R[k][j];
                    }
                }
            }
        }
    }

    public double distanciaMinima(int src, int dst){
        return L[dst][src];
    }

    public LinkedList<Integer> caminhoMinimo(int src, int dst){
        LinkedList<Integer> lista = new LinkedList<>();
        lista.addFirst(dst+1);
        while(R[src][dst] != src){
            dst = R[src][dst];
            lista.addFirst(dst+1);
        }
        lista.addFirst(src+1);
        return lista;
    }
    //kruskal
    private int min(double k[], Boolean marcados[])
    {

        double min = Integer.MAX_VALUE;
        int minIndice=-1;

        for (int v = 0; v < tamanho; v++)
            if (!marcados[v] && k[v] < min)
            {
                min = k[v];
                minIndice = v;
            }

        return minIndice;
    }


    private void imprimeArq(double parent[]) throws IOException  {
        BufferedWriter buffWrite = new BufferedWriter(new FileWriter("arvore2.txt"));
        String imprime = "";
        double tamanhomax = 0;
        for (int i = 1; i < tamanho; i++) {
            imprime = imprime.concat((int) parent[i] + " " + i + " " + matrizValores[i][(int) parent[i]] + "\n");
            tamanhomax = tamanhomax + matrizValores[i][(int) parent[i]];
        }
        imprime = imprime.concat("tamanho total: "+ tamanhomax + "");
        buffWrite.append(imprime);

        buffWrite.close();
    }

    void primArvoreMin() throws IOException {

        double parent[] = new double[tamanho];


        double k[] = new double [tamanho];


        Boolean mstSet[] = new Boolean[tamanho];


        for (int i = 0; i < tamanho; i++)
        {
            k[i] = Integer.MAX_VALUE;
            mstSet[i] = false;
        }


        k[0] = 0;

        parent[0] = -1;


        for (int count = 0; count < tamanho-1; count++)
        {

            int u = min(k, mstSet);


            mstSet[u] = true;


            for (int v = 0; v < tamanho; v++)


                if (matrizValores[u][v]!=0 && !mstSet[v]&&
                        matrizValores[u][v] < k[v])
                {
                    parent[v] = u;
                    k[v] = matrizValores[u][v];
                }
        }


        imprimeArq(parent);
    }

    public boolean isEuleriano (){
        if (numComponentesConexas() > 1){
            return false;
        }
        for (int i = 0; i< this.tamanho; i++ ){
            if (getOrdemVertice(i) % 2 == 1)
                return false;
        }
        return true;
    }

    public LinkedList<V> conjuntoIndependente (){
        LinkedList<V> S = new LinkedList<>();
        LinkedList<V> N = new LinkedList<>();
        V k;
        for(int i = 0; i < tamanho; i++)
            N.add(new V(i));

        Collections.sort(N, new Comparator<V>() {
            @Override
            public int compare(V o1, V o2) {
                return o1.graus - o2.graus;
            }
        });
        while(!N.isEmpty()){
            k = N.getFirst();
            N.remove(k);
            for(int i : getVizinhosVertice(k.indice)){
                N.remove(procuraV(N, i));
            }
            S.add(k);
        }
        return S;
    }

    private V procuraV(LinkedList<V> l, int indice){
        for(V v: l){
            if(v.indice == indice){
                return v;
            }
        }
        return null;
    }
}
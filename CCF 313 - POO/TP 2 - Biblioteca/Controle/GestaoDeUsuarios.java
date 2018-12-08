package br.caf.ufv.biblioteca.Controle;

import br.caf.ufv.biblioteca.Dados.Usuario;

import java.util.*;
import java.io.*;

public class GestaoDeUsuarios {
    private HashMap<Integer, Usuario> UserList = new HashMap<>();

    public HashMap<Integer, Usuario> getUserList() {
        return UserList;
    }

    public GestaoDeUsuarios ()throws IOException, NullPointerException{
        File file = new File("../POO1/src/br/caf/ufv/biblioteca/Texts/Usuarios.txt");
        Scanner s = new Scanner(file);

        s.useDelimiter(";\\s*");
        while (s.hasNext()) {
            Usuario user = new Usuario();
            user.SetMatricula(s.nextInt());
            user.SetSenha(s.next());
            user.SetEndereco(s.next());
            UserList.put(user.GetMatricula(), user);
        }
    }

    public boolean Autentica(int matricula, String senha){ return AutenticaUser(matricula, senha); }

    private boolean AutenticaUser(int matricula, String senha) throws NullPointerException{
        int n = this.UserList.size();

        for (int key: this.UserList.keySet()) {
            if (UserList.get(key).GetMatricula() == matricula){
                if(UserList.get(key).GetSenha().equals(senha)) {
                    return true;
                }
                else
                    break;
            }
        }
        return false;
    }
}

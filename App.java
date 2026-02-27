public class App {
    public static void main(String[] args) {
        var p1 = new Paciente();
        p1.setCodigo(5);
        p1.setNome("jose da silva");
        p1.setEmail("jose@norton.net.br");
        p1.mostrar();
        
        var p2 =new Paciente(1, "maria souza", "maria@northon.com.br");
        p2.mostrar();

    }
}

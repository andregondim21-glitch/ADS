public class Paciente {
    int codigo;
    String nome;
    String cpf;
    String telefone;
    String genero;
    int idade;
    String email;

    public void cadastrar(){
        //TODO
    }
    public void consultar(){
        //TODO
    }
    public int getCodigo() {
        return codigo;
    }
    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }
    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getCpf() {
        return cpf;
    }
    public void setCpf(String cpf) {
        this.cpf = cpf;
    }
    public String getTelefone() {
        return telefone;
    }
    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }
    public String getGenero() {
        return genero;
    }
    public void setGenero(String genero) {
        this.genero = genero;
    }
    public int getIdade() {
        return idade;
    }
    public void setIdade(int idade) {
        this.idade = idade;
    }
    public String getEmail()  {
        return email;
    }
    public void setEmail(String email) throws Exception {
        if(email==null || email.length() < 6 || !email.contains("@")){
            throw new Exception("Email completo obrigatorio!!");
        } else{
            this.email = email;
        }
        
    }

    public Paciente(){
        this.codigo=0;
        this.nome="";
        this.cpf="";
        this.telefone="";
        this.genero="";
        this.idade=0;
        this.email="";
    }

    public Paciente(int pCodigo, String pNome, String pCpf, String pTelefone, String pGenero, int pIdade, String pEmail) throws Exception{
        setCodigo(pCodigo);
        setNome(pNome);
        setCpf(pCpf);
        setTelefone(pTelefone);
        setGenero(pGenero);
        setIdade(pIdade);
        setEmail(pEmail);
    }
    public void mostrar(){
        System.out.println(">>>>>>Paciente<<<<<<<");
        System.out.println("codigo:"+getCodigo());
        System.out.println("nome:"+getNome());
        System.out.println("cpf:"+getCpf());
        System.out.println("tel:"+getTelefone());
        System.out.println("Genero:"+getGenero());
        System.out.println("idade:"+getIdade());
        System.out.println("email:"+getEmail());
    }
}

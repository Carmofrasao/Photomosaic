import run from "./src/saida.js";

const gerarFotomosaico = document.querySelector("#gerarFotomosaico");

gerarFotomosaico.addEventListener('click', () => {
  const caminhoImagemOriginal = document.getElementById("inputImagemOriginal").value;
  const diretorioSelecionado = document.getElementById("selectDiretorioImagens").value;
  let entrada = "-p "+diretorioSelecionado+" -i "+caminhoImagemOriginal+" -o saida.ppm";
  console.log(entrada);
  run(entrada);  
  entrada = "";
})


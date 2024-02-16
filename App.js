
function gerarFotomosaico() {
    var caminhoImagemOriginal = document.getElementById("inputImagemOriginal").value;
    var caminhoConjuntoImagens = document.getElementById("inputConjuntoImagens").value;
    
    // Verifique se os caminhos dos arquivos foram fornecidos
    if (caminhoImagemOriginal && caminhoConjuntoImagens) {
        // Chame a função do módulo WebAssembly para gerar o fotomosaico
        Module.ccall('generatePhotomosaic', 'number', ['string', 'string'], [caminhoImagemOriginal, caminhoConjuntoImagens]);
        
        // Uma vez que a função é chamada, você pode querer exibir o resultado na tela ou fazer outra coisa com ele
        // Por exemplo, você pode atualizar uma imagem na página com o resultado gerado
    } else {
        alert("Por favor, selecione a imagem original e o conjunto de imagens para gerar o fotomosaico.");
    }
}

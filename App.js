fetch('./src/saida.wasm')
    .then(response => response.arrayBuffer())
    .then(buffer => WebAssembly.instantiate(buffer))
    .then(module => {
        Module = module.instance.exports;
        // Redefinir a função gerarFotomosaico com Module definido
        function gerarFotomosaico() {
            var caminhoImagemOriginal = document.getElementById("inputImagemOriginal").value;
            var diretorioSelecionado = document.getElementById("selectDiretorioImagens").value;
            console.log("chegou aqui");
            // Verifique se os caminhos dos arquivos foram fornecidos
            if (caminhoImagemOriginal && diretorioSelecionado) {
                // Chame a função do módulo WebAssembly para gerar o fotomosaico
                console.log("chegou aqui 1");
                Module.ccall('main', 'number', ['string', 'string'], ['./'+caminhoImagemOriginal, diretorioSelecionado]);
                console.log("chegou aqui 2");
                // Uma vez que a função é chamada, você pode querer exibir o resultado na tela ou fazer outra coisa com ele
                // Por exemplo, você pode atualizar uma imagem na página com o resultado gerado
            } else {
                alert("Por favor, selecione a imagem original e o conjunto de imagens para gerar o fotomosaico.");
            }
        }
        // O módulo WebAssembly está carregado, você pode chamar sua função principal aqui
        gerarFotomosaico();
    })

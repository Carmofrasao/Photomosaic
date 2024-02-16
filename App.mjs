import "./src/saida.js";

// let Module = null;
// fetch('./src/saida.wasm')
//     .then(response => response.arrayBuffer())
//     .then(buffer => WebAssembly.instantiate(buffer, {
//        wasi_snapshot_preview1: wasi.wasiImport,
//        env: {
//          exit(_msg, _file, line, column) {
//            console.error("abort called at main.ts:" + line + ":" + column);
//          }
//        },
//     }))
// .catch(e => { console.log('here'); console.error(e); })
//     .then(module => {
//         Module = module.instance.exports;
//         // Redefinir a função gerarFotomosaico com Module definido
//         // O módulo WebAssembly está carregado, você pode chamar sua função principal aqui
//         gerarFotomosaico();
//     })
// 
// function gerarFotomosaico() {
//     var caminhoImagemOriginal = document.getElementById("inputImagemOriginal").value;
//     var diretorioSelecionado = document.getElementById("selectDiretorioImagens").value;
//     console.log("chegou aqui");
//     // Verifique se os caminhos dos arquivos foram fornecidos
//     if (caminhoImagemOriginal && diretorioSelecionado) {
//         // Chame a função do módulo WebAssembly para gerar o fotomosaico
//         Module.ccall('main', 'number', ['string', 'string'], ['./'+caminhoImagemOriginal, diretorioSelecionado]);
//         // Uma vez que a função é chamada, você pode querer exibir o resultado na tela ou fazer outra coisa com ele
//         // Por exemplo, você pode atualizar uma imagem na página com o resultado gerado
//     } else {
//         alert("Por favor, selecione a imagem original e o conjunto de imagens para gerar o fotomosaico.");
//     }
// }

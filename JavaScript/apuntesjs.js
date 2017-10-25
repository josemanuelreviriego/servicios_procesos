function Log(div) { // lo que hagas en log cambiara para cada objeto
    this.mssgs = []
    this.output = document.getElementById(div)
}

Log.prototype.dump = funtion (){ // lo que hagas en el prototipo afecta a todos los objetos
    this.output.innerHTML = this.mssgs.toString()
}

Log.prototype.log = function (mssg){
    this.mssgs.push(new Date() + ": " + mssg + "<br/>\n")
    this.dump()
}

function main() {

var logger = new log("log")  //Crear un objeto
logger.log("Hola. Aplicacion iniciada") //Aqui esta tirando del prototipo para que consiga las funciones
logger.log("Esperando Comandos")

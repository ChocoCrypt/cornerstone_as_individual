import pyfirmata
import json
import time
# no sé si sea necesario importar la librería para hacer queries a la base de datos o si sea necesario simplemente exportar los objetos tipo JSON



def temperature(pin): #no sé que significa pt, por lo que puse pin
    #este board lo estoy inicializando acá sin embargo no sé si tenga sentido inicializarlo antes del while(que equivale al void loop)   |vie nov 13 20:23:04 -05 2020|
    board = pyfirmata.Arduino('/dev/ttyACM0')
    pt = None
    t = 0 #no sé si t haga referencia a una unidad de tiempo o para que sirve
    dht = pyfirmata.util.Iterator(board)
    dht.start()
    #ACA ES DONDE TINEN QUE PONER EL PIN de donde está el s   |vie nov 13 20:24:56 -05 2020|
    digital_input = board.get_pin('d:10:i')
    print("temperatura:")
    print(digital_input)
    #no estoy seguro de este digital_input , depronto tiene un metodo para leerlo
    pass


def ph_test(pin):
    #comentarios analogos al anterior   |vie nov 13 20:31:59 -05 2020|
    board = pyfirmata.Arduino('/dev/ttyACM0')
    pt = None
    t = 0

    dht = pyfirmata.util.Iterator(board)
    dht.start()
    pass

    digital_input = board.get_pin('d:10:i')
    print("ph...")
    print(digital_input)
    #la forma de agarrar    |vie nov 13 20:33:48 -05 2020|


def bomb_h(pin):
    board = pyfirmata.Arduino('/dev/ttyACM0')
    pt = None
    t = 0

    dht = pyfirmata.util.Iterator(board)
    dht.start()
    pass

    digital_input = board.get_pin('d:10:i')
    print("bomb...")
    print(digital_input)
    #acá es donde tienen que leerlo de la documentación   |vie nov 13 20:38:23 -05 2020|
    pass



#ESTO NO SE SI TENGA SENTIDO INICIALIZARLO ACÁ PERO NO SÉ QUE SENTIDO TENÍA EN EL CÓDIGO   |vie nov 13 20:48:29 -05 2020|
hilo1 = None
hilo2  = None
hilo3  = None
hilo4 = None

#ESTO ES EQUIVALENTE AL VOID LOOP   |vie nov 13 20:48:18 -05 2020|
while(True):
    temperature(hilo1)
    ph_test(hilo2)
    bomb_h(hilo3)

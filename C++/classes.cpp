class Vector3 {
    double x;
    double y;
    double z;

public:
    Vector3(double x, double y, double z) {

    }

    double get_x() {
        return x;
    }

    double get_y() {
        return y;
    }

    double get_z() {
        return z;
    }
};

class Cone {
    Vector3 position;

    // Esempio di costruttore che non riceve parametri: devo inizializzare il parametro
    // `position` della classe prima di entrare nel corpo del costruttore, con la sintassi sottostante
    Cone () : position(0, 0, 0) {

    }
    // Esempio di costruttore ricevemente parametro
    Cone (Vector3 pos) : position(pos.get_x(), pos.get_y(), pos.get_z()) {

    }

    ~Cone() {
        // Operazioni di cleanup (es. risorse allocate dinamicamente)
    }
};
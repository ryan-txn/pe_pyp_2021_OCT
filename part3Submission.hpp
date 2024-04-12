

void HashTable::insert(int n) {
    if (exist(n)) {
        cout << n << " already exists in the hash table."<< endl;
    } else {
        int col = 0;
        int hash = (h(n) % _size);
        while (((_ht[hash] != 0)) && (_ht[hash] != -1)) { // fill the hash if empty or deleted
            col++;
            hash = (h(n) + (col * col)) % _size;
        }
        _ht[hash] = n;
        _nItem++;
    }
}

//n does not necasarrily exist in the hash table
void HashTable::remove(int n) {
    int hash = (h(n) % _size);
    int col = 0;
    while (_ht[hash] != n) {
        if (_ht[hash] == 0) {
            cout <<"Fail to remove " << n << endl;
            return;
        }
        col++;
        hash = (h(n) + (col * col)) % _size;
    }
    _ht[hash] = -1;
    _nItem--;
    // default output format for error message
    //cout << "Fail to remove " << n << endl;
}

bool HashTable::exist(int n) {
    int hash = (h(n) % _size);
    int col = 0;
    while (_ht[hash] != n) {
        if (_ht[hash] == 0) {
            return false;
        }
        col++;
        hash = (h(n) + (col * col)) % _size;
    }
    return true;
}


void HashTable::resize(int newSize) {
    int *old = _ht;
    int oldSize = _size;
    _size = newSize;
    _ht = new int[_size];
    for (int j = 0; j < _size; j++) {
		_ht[j] = 0;
	}
    for (int i = 0; i < oldSize; i++) {
        if (old[i] != 0 && old[i] != -1) {
            insert(old[i]);
        }
    }
    delete[] old;
}

int n3Sum(int* arr, int size, int total)
{
    return 0;
}

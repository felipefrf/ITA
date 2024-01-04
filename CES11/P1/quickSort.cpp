int vec[21];
int aux;

int partition(int init, int end){
    int pivot, left, right;

    pivot = vec[init];
    left = init + 1;
    right = end;

    do{
        while(left < end and vec[left] < pivot) left++;
        while(right > init and vec[right >= pivot]) right--;
        if(left < right){
            aux = vec[right];
            vec[right] = vec[left];
            vec[left] = aux;
        }
    }while(left < right);

    vec[init] = vec[right];
    vec[right] = pivot;

    return right;
}
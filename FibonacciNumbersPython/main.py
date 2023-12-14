def get_fibonacci_numbers(endIt):
    arr = [0, 1, 1]
    for i in range(1, endIt - 2):
        arr.append(arr[i] + arr[i + 1])

    for num in arr:
        print(f'{num} ', end='')

def get_fibonacci_numbers_to_file(endIt, fileName):
    arr = [0, 1, 1]
    for i in range(1, endIt - 2):
        arr.append(arr[i] + arr[i + 1])

    try:
        with open(fileName, 'w') as file:
            numbers = ''
            for num in arr:
                numbers += f'{num} '
            file.write(numbers)
        print(f'\n{fileName} succesfully created!\n')
    except Exception as e:
        raise Exception(f'\nException occured during writing file: {e}!\n')
    

get_fibonacci_numbers(10)
get_fibonacci_numbers_to_file(20, 'fibonacci_number.txt')
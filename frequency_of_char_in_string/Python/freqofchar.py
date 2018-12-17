def freqOfCharInStr(string):
    # convert string to array
    my_list = list(string)
    
    # declare an empty dictionary
    my_dict = {}

    # run variable
    i = 0
    j = 0
    # frequency of char
    count = 0
    # get the number of elements in list
    length = len(my_list)

    # loop through the list
    while(i < length):
        # every character appears at least once
        count = 1
        # if we hit the last char, put the data of char(my_list[i]) and count(which is defaultly 1) into the dictionary `my_dict`
        if(i == length - 1):
            my_dict[my_list[i]] = count
            # then exit the loop, since we reach the last element
            break
        else:
            # if not, get the next index
            j = i + 1


        # compare 2 consecutive elements in the list, if they are the same
        #  increase the `count` by 1
        #  delete second char from the list(del my_list[j]), my_list[j]:char you want to delete from the list
        #  decrease the length by 1
        while(my_list[i] == my_list[j]):
            count += 1
            del my_list[j]
            length -= 1
            # if we reach the last character when remove char, exit the loop
            if(i == length - 1):
                break


        # put the char and its current freq(count) into the dictionary
        my_dict[my_list[i]] = count
        # increase the run vairable so that it won't cause the infinite loop
        i += 1


    # give back the dictionary
    return my_dict

# print the char and its freq follows format
def printDict(the_dict):
    # get all the keys in the dictionary, which is the char
    my_keys = the_dict.keys()
    # sort the array of keys, since they are not in alphabeltic order
    order_keys = sorted(my_keys)
    # loop through each key in the array of keys, print the char and its freq(`the_dict.get(my_key)`)
    for my_key in order_keys:
        print("\'",my_key,"\' :",the_dict.get(my_key))
def stringFormat(string):
    # remove all the spaces
    noSpaceStr = string.replace(" ","")

    # convert uppercase to lowercase
    lwrStr = noSpaceStr.lower()

    # sort the string
    # sort the string and return a list
    sortArr = sorted(lwrStr)
    # make an empty string
    sortStr = ""
    # conver the sorted array to the string
    sortStr = sortStr.join(sortArr)

    return sortStr
import csv
from collections import defaultdict, Counter

# This program allows you to organize pokemon data


idD = {}

nameD = {}

levelD = {}

personalityD = {}

typeD = {}

weaknessD = {}

atkD = {}

defD = {}

hpD = {}

stageD = {}

with open('pokemonTrain.csv') as csv_file:
    lineCt = 1

    ct = 0


    fireCt = 0

    next(csv.reader(csv_file))

# organizes the file by separating into lines
    for row in csv.reader(csv_file, delimiter=','):

        idD[lineCt] = row[0]

        nameD[lineCt] = row[1]

        levelD[lineCt] = row[2]

        personalityD[lineCt] = row[3]

        typeD[lineCt] = row[4]

        weaknessD[lineCt] = row[5]

        atkD[lineCt] = row[6]

        defD[lineCt] = row[7]

        hpD[lineCt] = row[8]

        stageD[lineCt] = row[9]


# finds the % of of fire type that are above level 40
        if float(row[2]) >= 40 and row[4] == 'fire':

            ct += 1
            fireCt += 1

        elif row[4] == 'fire':

            fireCt += 1

        lineCt += 1

    perc = round(ct / fireCt * 100)

    f = open("pokemon1.txt", "a")
    f.write("Percentage of fire type Pokemons at or above level 40 = " + str(perc))

# Fill in the missing “type” column values (given by NaN) by mapping
# them from the corresponding “weakness” values.

weaknessT = defaultdict(list)


for key, val in weaknessD.items():

    weaknessT[val].append(typeD[key])

weanknessCt = {}

output = {}

for key, val in weaknessT.items():

    val = sorted(val, key=lambda x: x[0].lower())
    ct = Counter(val)

    for kk in ct.items():

        if kk == 'NaN':

            ct[kk] = 0

    weanknessCt[key] = list(dict(sorted(ct.items(), key=lambda x: x[0], reverse=True)))

    output[key] = weanknessCt.get(key)[0]

for key, val in typeD.items():

    if val == 'NaN':

        typeD[key] = output[weaknessD[key]]





# Adjusts the treshold and sets the pokemon level threshold to 40.

hiatk = 0

highDf = 0

highHp = 0

atk = 0

defns = 0

hp = 0

haCnt = 0

hdCnt = 0

hhCnt = 0

acnt = 0

dCnt = 0

hCnt = 0

for key, val in levelD.items():

    if float(val) <= 40.0:

        if atkD[key] != 'NaN':

            atk += float(atkD[key])

            acnt += 1

        if defD[key] != 'NaN':

            defns += float(defD[key])

            dCnt += 1

        if hpD[key] != 'NaN':

            hp += float(hpD[key])

            hCnt += 1
    else:
        if atkD[key] != 'NaN':

            hiatk += float(atkD[key])

            haCnt += 1

        if defD[key] != 'NaN':

            highDf += float(defD[key])

            hdCnt += 1

        if hpD[key] != 'NaN':

            highHp += float(hpD[key])

            hhCnt += 1

for key, val in atkD.items():

    if float(levelD[key]) > 40.0 and val == 'NaN':

        atkD[key] = round(hiatk / haCnt, 1)

    elif float(levelD[key]) <= 40.0 and val == 'NaN':

        atkD[key] = round(atk / acnt, 1)

for key, val in defD.items():

    if float(levelD[key]) > 40.0 and val == 'NaN':

        defD[key] = round(highDf / hdCnt, 1)

    elif float(levelD[key]) <= 40.0 and val == 'NaN':

        defD[key] = round(defns / dCnt, 1)

for key, val in hpD.items():

    if float(levelD[key]) > 40.0 and val == 'NaN':

        hpD[key] = round(highHp / hhCnt, 1)

    elif float(levelD[key]) <= 40.0 and val == 'NaN':

        hpD[key] = round(hp / hCnt, 1)

#  Create a dictionary that maps pokemon types to their personalities.
# This dictionary would map a string to a list of strings. For example:

with open('pokemonResult.csv', 'w', newline='') as out:

    col = ['id', 'name', 'level', 'personality', 'type', 'weakness', 'atk', 'def', 'hp', 'stage']
    csv.writer(out).writerow(col)

    for key, val in idD.items():

        csv.writer(out).writerow([idD[key], nameD[key], levelD[key], personalityD[key],
                                  typeD[key], weaknessD[key], atkD[key], defD[key], hpD[key], stageD[key]])




with open('pokemonResult.csv') as csv_file:

    hhp = 0

    sCount = 0

    pt_dict = defaultdict(list)

    next(csv.reader(csv_file))

    for row in csv.reader(csv_file, delimiter=','):

        if row[3] not in pt_dict[row[4]]:

            pt_dict[row[4]].append(row[3])

        if row[9] == "3.0":

            hhp += float(row[8])

            sCount += 1

sort = dict(sorted(pt_dict.items(), key=lambda x: x[0].lower()))

for key, val in sort.items():

    sort[key] = sorted(val, key= lambda x: x[0].lower())

with open('pokemon4.txt', "w") as out:

    out.write("Pokemon type to personality mapping:\n\n")

    for key, val in sort.items():

        out.write('\t%s: %s\n' % (key, ', '.join(val)))

avghp = round(hhp/sCount)

# Find out the average Hit Points (“hp”) for pokemon of stage 3.0.
# Your program should print the value as follows (replace . . . with value):

with open('pokemon5.txt', "w") as out:
    
    out.write("Average hit point for Pokemons of stage 3.0 = " + str(avghp))
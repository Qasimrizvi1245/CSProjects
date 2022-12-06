import csv

from collections import defaultdict, Counter

# this program organizes the file by syptoms

idD = {}

ageD = {}

genderD = {}

cityD = {}

provinceD = {}

countryD = {}

latD = {}

longD = {}

dateofSymD = {}

dateAdminHosD = {}

dateConfirmD = {}

symptomsD = {}

with open('covidTrain.csv') as csvfile:

    next(csv.reader(csvfile))

    lines = 1

# separates the file into rows

    for row in csv.reader(csvfile):

        idD[lines] = row[0]

        ageD[lines] = row[1]

        genderD[lines] = row[2]

        cityD[lines] = row[3]

        provinceD[lines] = row[4]

        countryD[lines] = row[5]

        latD[lines] = row[6]

        longD[lines] = row[7]

        dateofSymD[lines] = row[8]

        dateAdminHosD[lines] = row[9]

        dateConfirmD[lines] = row[10]

        symptomsD[lines] = row[11]


        lines += 1




# 1) this changes the date format from 01-01-2022 to 01.01.2022
for key, val in ageD.items():


    if ageD[key].__contains__('-'):


        ageD[key] = round((int(ageD[key].split('-')[0]) + int(ageD[key].split('-')[1])) / 2)


for key, val in dateofSymD.items():


    dateofSymD[key] = dateofSymD[key].split('.')[1] \
                                  + "." + dateofSymD[key].split('.')[0] \
                                  + "." + dateofSymD[key].split('.')[2]

    dateAdminHosD[key] = dateAdminHosD[key].split('.')[1] \
                                      + "." + dateAdminHosD[key].split('.')[0] \
                                      + "." + dateAdminHosD[key].split('.')[2]

    dateConfirmD[key] = dateConfirmD[key].split('.')[1] \
                                + "." + dateConfirmD[key].split('.')[0] \
                                + "." + dateConfirmD[key].split('.')[2]


# 2) Fills in the missing (NaN) latitude and longitude values by the average of the latitude
# and longitude values for the province where the case was
# recorded. Round the average to 2 decimal places.

lat = defaultdict(list)


long = defaultdict(list)

for key, val in provinceD.items():


    lat[val].append(latD[key])


    long[val].append(longD[key])

total = 0


items = 0

for key, val in lat.items():


    total = 0


    items = 0


    for s in val:


        if s != 'NaN':


            total += float(s)


            items += 1


    lat[key] = round(total/items, 2)


for key, val in long.items():
    total = 0
    items = 0
    for s in val:


        if s != 'NaN':


            total += float(s)


            items += 1
    long[key] = round(total/items, 2)

for key, val in latD.items():
    if latD[key] == 'NaN':


        latD[key] = str(lat[provinceD[key]])
for key, val in longD.items():


    if longD[key] == 'NaN':


        longD[key] = str(long[provinceD[key]])


# Fills in the missing city values by the most occurring city value in
# that province. In case of key tie, use the city that appears first in alphabetical
# order.




provinceT = defaultdict(list)

for key, val in provinceD.items():


    provinceT[val].append(cityD[key])

cityC = {}


result = {}

for key, val in provinceT.items():


    val = sorted(val, key=lambda x: x[0].lower())


    cnt = Counter(val)

    for kk in cnt.items():


        if kk == 'NaN':


            cnt[kk] = 0

# reg expression


    cityC[key] = list(dict(sorted(cnt.items(), key=lambda x: x[0], reverse=True)))


    result[key] = cityC.get(key)[0]

for key, val in cityD.items():


    if val == 'NaN':


        cityD[key] = result[provinceD[key]]



provinceC = defaultdict(list)

for key, val in provinceD.items():


    provinceC[val].append(symptomsD[key])


    for kk in provinceC[val]:



        if kk.__contains__(';'):


            provinceC[val].remove(kk)


            temp = kk.split(';')


            for ele in temp:


                temp = str(ele).strip()
            provinceC[val].append(temp)

    for k3 in provinceC[val]:


        if k3 == 'NaN':


            provinceC[val].remove(k3)

print(provinceC)

#  Fill in the missing symptom values by the single most frequent
# symptom in the province where the case was recorded. In case of key tie, use
# the symptom that appears first in alphabetical order.

ttemp = []


outputput = {}

for key, val in provinceC.items():


    val = sorted(val, key=lambda x: x[0].lower())
    cnnt = Counter(val)
    cnt_dict = dict(cnnt)



    cnt_dict = dict(sorted(cnt_dict.items(), key=lambda x: x[1], reverse = True))


    cnt_dict = list(cnt_dict.keys())


    print(cnt_dict)

    outputput[key] = cnt_dict[0]

    print(outputput)

for key, val in symptomsD.items():


    if val == 'NaN':


        symptomsD[key] = outputput[provinceD[key]]


with open('covidResult.csv', 'w', newline='') as out:

    col = ['ID', 'age', 'sex', 'city', 'province', 'country', 'latitude', 'longitude', 'date_onset_symptoms',
                                  'date_admission_hospital', 'date_confirmation', 'symptoms']
    csv.writer(out).writerow(col)


    for key, val in idD.items():
        csv.writer(out).writerow([idD[key], ageD[key], genderD[key], cityD[key], provinceD[key], countryD[key],
                                  latD[key], longD[key], dateofSymD[key],
                                  dateAdminHosD[key], dateConfirmD[key], symptomsD[key]])
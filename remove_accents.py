import re
import unicodedata

def remove_accents(input_str):
    nfkd_form = unicodedata.normalize('NFKD', input_str)
    return u"".join([c for c in nfkd_form if not unicodedata.combining(c)])

files = ['data/maps/LittlerootTown/scripts.inc', 
         'data/maps/LittlerootTown_BrendansHouse_1F/scripts.inc',
         'data/maps/LittlerootTown_MaysHouse_2F/scripts.inc',
         'data/maps/Route101/scripts.inc',
         'data/text/birch_speech.inc']

for filepath in files:
    with open(filepath, 'r', encoding='utf-8') as f:
        content = f.read()
    
    # Replace special characters with unaccented versions
    content = remove_accents(content)
    # Also replace Pokemon -> POKeMON, if it was changed
    content = content.replace("POKeMON", "POKeMON") # Wait, remove_accents changes POKéMON to POKeMON anyway.
    
    with open(filepath, 'w', encoding='utf-8') as f:
        f.write(content)

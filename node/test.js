const tiles = require('../src/core/tiles.json')

let suit_types = [];
tiles.forEach(tile => {
    for(let i = 0; i < suit_types.length; ++i)
    {
        if(suit_types[i] == tile.suit_type)
            return;
    }
    suit_types.push(tile.suit_type);
})
console.log("suit_types:", suit_types);
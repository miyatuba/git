Asset = {};
Asset.assets = [
	{type:'image', name: 'joker', src: 'joker.png'},
];

Asset.images = {};

Asset.loadAssets = function(onComplete) {
	var total = Asset.assets.length;
        var loadCount = 0;

	var onLoad = function () {
		loadCount++;
		if (loadCount >= total) {
			onComplete();
		}
	};
	
	//‘S‚Ä“Ç‚İ‚İ
	Asset.assets.forEach(function(asset)) {
		switch (asset.type){
			case 'image':
				Asset._loadImage(asset, onLoad);
				break;
		}
	});
};

Asset._loadImage = function(asset, onLoad) {
	var image = new Image();
	image.src = asset.src;
    image.onload = onLoad;
    Asset.images[asset.name] = image;
};
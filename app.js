const localAudio = document.getElementById('localAudio');
const remoteAudio = document.getElementById('remoteAudio');
let localStream;
let peerConnection;

const servers = {
    iceServers: [
        {
            urls: 'stun:stun.l.google.com:19302'
        }
    ]
};

async function startLocalStream() {
    localStream = await navigator.mediaDevices.getUserMedia({ audio: true });
    localAudio.srcObject = localStream;
}

async function startCall() {
    peerConnection = new RTCPeerConnection(servers);
    localStream.getTracks().forEach(track => peerConnection.addTrack(track, localStream));

    peerConnection.ontrack = event => {
        remoteAudio.srcObject = event.streams[0];
    };

    const offer = await peerConnection.createOffer();
    await peerConnection.setLocalDescription(offer);

    // Send offer to the signaling server
    const response = await fetch('http://localhost:8080', {
        method: 'POST',
        body: JSON.stringify({ offer })
    });
    const { answer } = await response.json();
    await peerConnection.setRemoteDescription(answer);
}

startLocalStream();
